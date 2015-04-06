## How to Install Java Dimmunix Vaccination Framework? ##

Check out Java Dimmunix Vaccination Framwork
```
svn checkout http://dimmunix.googlecode.com/svn/trunk/java/src/Vaccine 
```

## How to Use Dimmunix Vaccination Framework on Java Programs? ##

You need to make some changes in the build.xml file, which is under Vaccine folder

1. You need to specify the path of the program bytecode for the program you want to check. (First "arg value" in build.xml)

2. The signatures to be validated should be given in a file and path to that file should be specified. (Second "arg value" in build.xml)

3. Paths to the necessary bytecode and .jar files should be specifed ("pathelement location" in build.xml)

4. Then you can run the dimmunix vaccination framework
```
cd <path to Dimmunix Vaccination Framework>
ant run
```

## Example With MySQL JDBC 5.0 ##

You can check out MySQL JDBC 5.0
```
svn checkout http://dimmunix.googlecode.com/svn/trunk/java/test/mysql-connector-java-5.0.0-beta 
```

The Vaccine/build.xml file contains an example for trying the vaccination framework with MySQL JDBC 5.0.

The Vaccine/src/signatures/JDBCMySQLSigs contains two valid deadlock signatures for MySQL JDBC 5.0.

However, you should update the paths in build.xml according to where you checked out MySQL JDBC 5.0 and Dimmunix Vaccination Framework.


Below there is an example build.xml file for validating the deadlock signatures in Vaccine/src/signatures/JDBCMySQLSigs;



&lt;java classname="evaluation.Evaluation" fork="true"&gt;


> 

&lt;arg value="&lt;path to MySQL JDBC 5.0&gt;/mysql-connector-java-5.0.0-beta/bin"/&gt;


> 

&lt;arg value="&lt;path to Dimmunix Vaccine Framework&gt;/Vaccine/src/signatures/JDBCMySQLSigs"/&gt;


> 

&lt;classpath&gt;


> > 

&lt;path refid="classpath" /&gt;


> > 

&lt;pathelement location="${build.dir}" /&gt;


> > 

&lt;pathelement location="&lt;path to MySQL JDBC 5.0&gt;/mysql-connector-java-5.0.0-beta/bin" /&gt;


> > 

&lt;pathelement location="&lt;path to MySQL JDBC 5.0&gt;/mysql-connector-java-5.0.0-beta/bin/lib/junit.jar" /&gt;


> > 

&lt;pathelement location="&lt;path to MySQL JDBC 5.0&gt;/mysql-connector-java-5.0.0-beta/bin/lib/jboss-common-jdbc-wrapper.jar" /&gt;


> > 

&lt;pathelement location="&lt;path to MySQL JDBC 5.0&gt;/mysql-connector-java-5.0.0-beta/bin/lib/log4j-1.2.9.jar" /&gt;


> > 

&lt;pathelement location="&lt;path to MySQL JDBC 5.0&gt;/mysql-connector-java-5.0.0-beta/bin/lib/c3p0-0.8.5-pre8.jar" /&gt;


> > 

&lt;pathelement location="&lt;path to MySQL JDBC 5.0&gt;/mysql-connector-java-5.0.0-beta/bin/lib/jta-spec1\_0\_1.jar" /&gt;



> 

&lt;/classpath&gt;


> 

&lt;jvmarg value="-Xmx2000m" /&gt;


> 

&lt;jvmarg value="-Xss128m" /&gt;


> 

&lt;jvmarg value="-Djava.srcdir=src" /&gt;


> 

&lt;jvmarg value="-Djava.sigPath=signatures" /&gt;


> 

&lt;/java&gt;



You might also need to add the classpath to jsse.jar, e.g.,


&lt;pathelement location="/usr/lib/jvm/java-6-sun-1.6.0.16/jre/lib/jsse.jar" /&gt;
