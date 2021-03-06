/*
     Created by Horatiu Jula, George Candea, Daniel Tralamazza, Cristian Zamfir
     Copyright (C) 2009 EPFL (Ecole Polytechnique Federale de Lausanne)

     This file is part of Dimmunix.

     Dimmunix is free software: you can redistribute it and/or modify it
     under the terms of the GNU General Public License as published by the
     Free Software Foundation, either version 3 of the License, or (at
     your option) any later version.

     Dimmunix is distributed in the hope that it will be useful, but
     WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
     General Public License for more details.

     You should have received a copy of the GNU General Public
     License along with Dimmunix. If not, see http://www.gnu.org/licenses/.

     EPFL
     Dependable Systems Lab (DSLAB)
     Room 330, Station 14
     1015 Lausanne
     Switzerland
*/

package dimmunix.deadlock;

import dimmunix.Util;
import dimmunix.Vector;

public class InnerPosition {
	public Vector<StackTraceElement> callStack = new Vector<StackTraceElement>(DimmunixDeadlock.instance.maxCallStackDepth);

	public InnerPosition(Vector<StackTraceElement> callStack) {
		this.callStack = callStack;
	}
	
	public InnerPosition() {		
	}
	
	public String toString() {
		StringBuffer sb = new StringBuffer();
		
		for (int i = 0; i < callStack.size(); i++) {
			if (i > 0)
				sb.append(",");
			sb.append(callStack.get(i));			
		}
		return sb.toString();
	}
	
	public void add(String frame) {
		this.callStack.add(Util.parsePosition(frame));
	}
	
	public void add(StackTraceElement frame) {
		this.callStack.add(frame);
	}
	
	public void shrink(int newSize) {
		if (newSize >= this.callStack.size()) {
			return;
		}

		while (this.callStack.size() > newSize) {
			this.callStack.remove();			
		}
	}
}
