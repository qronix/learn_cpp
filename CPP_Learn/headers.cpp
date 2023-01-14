/*
	Headers can include other header files, this is known as transitive inclusion.
	You should NOT rely on transitive inclusion as the contents of implicitly included
	header files could change, resulting in a failure to compile.

	Instead, as a best practice, any required headers should be EXPLICITLY included,
	regardless of transitive inclusion; this ensures compilation will not fail if an
	implicitly included header file changes.

	Best practices for #include directives and header inclusion:

	-	Do not rely on transitive inclusion
	-	Explicitly include all required header files
	-	Do not include header files from other locations via relative paths
	-	Do include header files in other locations via project IDE include directories
	-	To maximize the chance that missing includes are flagged by the compiler,
		includes should follow the order of:

		- The paired header file (e.g. utils.cpp & utils.h)
		- Other headers from your project
		- Third-party library headers
		- Standard library headers

		These groups of headers should be grouped by type (paired, other project headers, third-party....)
		and listed in alphabetical order
	
	- Always include header guards
	- Do not define variables and functions in header files (excpet global constants)
	- Each header file should follow the architecture principle of separation of concerns
	- Every header you write should compile in isolation, i.e. the header includes everything it needs
	- Only #include what is necessary
	- Do not #include .cpp files
	- .cpp files should #include and define paired header functions to catch signature mismatches during
		the compilation phase and not the linking phase
*/
