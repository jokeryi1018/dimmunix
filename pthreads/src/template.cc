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

#include <algorithm>
#include <fstream>
#include "template.h"
#include "util.h"


namespace dlock {

ostream& operator << (ostream& os, const Template& tmpl) {
	os << tmpl.positions.size() << std::endl;
	foreach(vector<Position>::const_iterator, it, tmpl.positions)
		os << *it;
	return os;
}

istream& operator >> (istream& is, Template& tmpl) {
	size_t size;
	is >> size;
	Position p;
	for (size_t i = 0; i < size; ++i) {
		is >> p;
		tmpl.positions.push_back(p);
	}
	return is;
}

void Template::print() {
	foreach(vector<Position>::iterator, it, positions) {
		(*it).print_unlocked();
		printf_nonblocking("\n");
	}
}

void TemplateFactory::save_templates(vector<Template> &templs, const char* fname) {
	size_t n = templs.size();
	if (n <= 0)
		return;
	ofstream ofile;
	ofile.open(fname, ofstream::out | ofstream::trunc);
	ofile << templs.size() << std::endl;
	foreach(vector<Template>::iterator, it, templs)
		ofile << *it;
	ofile.close();
}

void TemplateFactory::load_templates(vector<Template> &templs, const char* fname) {
	ifstream ifile;
	ifile.open(fname);//, ifstream::in | ifstream::binary);
	if (!ifile.is_open())
		return;
	size_t n;
	ifile >> n;
	Template tmpl;
	int id = 1;
	while ((n > 0) && ifile.good()) {
		ifile >> tmpl;
		tmpl.id = id++;
		templs.push_back(tmpl);
		tmpl = Template();
		--n;
	}
	ifile.close();
	if (n > 0)
		DLOCK_DEBUGF("could not load all templates (%u) from %s\n", n, fname);
}

};

