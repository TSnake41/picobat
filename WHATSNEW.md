# What's New ? #

This a list of fixed bugs and improvements made :

**NOTE** : This list is not a complete list of improvements. The changes made 
before October 2012 were not included since the version started in this dates 
used almost new code.

## Friday 11st, October 2012 ##

* Added welcome screen \(Two versions\).

* Fixed a parsing bug \(The Function Dos9\_ParseStream\(\) always returned 
  NULL\).

* Added initialisation routine \( main\(\) \).

* Added support for testing existing files or dirs.

* Added support for current directory.

## Thursday 6th, December ##

* Added support of end of line.

* Added commutator '/n' to the command line.

* Added support for echoing.

* Sorted code files for a better understandability.

## Friday 4th, Junuary, 2013 ##

* added several commands \(TYPE/MORE, CLS, COLOR, TITLE, GOTO\).

* added support for english and french.

## Thursday 11th, February ##

* added api function for file matching \(i.e. paths using '\*' and '?'\).

* added function for cross-platform console management.

* added function to extended strings.

## Wednesday 20th, February ##

* fixed many portabiility issues for api.

* api is now cross-platform.

* Dos9 now works pretty well on linux.

* added lot of support for linux.

* fixed a bug with vars under linux.

* thought about use of dynamic files to easily change language.

* Dos9 runs 'Dos9\_Auto.bat' at launch, that initializes Variables to be 
  Cross-platform.

* Dos9 has now 3 native variables :

  * %DOS9\_OS% : The operating system that is currently running Dos9.

  * %DOS9\_VERSION% : The version of the running Dos9.

  * %DOS9\_PATH% : The path of Dos9 interpreter.

## Monday 11th, March ##

* Solve many portability issues \(i.e some programs did not work under 
  Linux\).

* Reprogrammed whole Man utility, which has been named "dman" to avoid 
  confusion on POSIX-compatible Systems.

  * DMan is able to run on several platforms natively.

  * DMan is more simple to use, since it makes it possible to use links man 
    pages.

* Fixed some bugs on BatMan.

* BatMan is now mainly portable.

* Fixed a bug in delayed variable expansion.

## Thursday 11th, April ##

* Corrected support of delayed expansion that didn't match to the way cmd.exe 
  parses it.

* Added support of expression evaluating \(might migrate to GNU LibMathEval 
  soon\).

* Added new kind of page support for dMan, it uses now a zip-compressed file 
  that contains several pages and saves up disk.

* Added a console-side text editor \(an alternative to BatMan\), GNU Nano.

* Modified nano to highlight batch code.

* Fixed a bug in a parameter for delayed expansion \(cEnableDelayedExpansion 
  was not taken account\).

## Thursday 12th, September ##

* Added UTF-8 support.

* Added different packages :

  * Dos9 Project HLP : A man page viewer.

  * Dos9 Project TEA : A simple, fast and tiny text processor.

  * Dos9 Project DUMP : A hex-dumper.

* Added i18n support \(through GNU gettext\).

* Added a README file.

## Tuesday 17th, September ##

* Fixed bug with the message **Error : "..." is not recognized as ...** 
  message in linux version.

* Fixed bug with the wait\(\) function in that made the program hold 
  indefinitely.

## Thursday 16th, October ##

* Changed build architecture. Now, the package can be built through a single 
  command line, that build all dependencies, i.e.:

        Make -B

* Added a lock specifier to the structure STREAMLVL that enables to fix bugs 
  with nested redirection levels. Like those that occured running the 
  following script:

        IF 1==1 (
         ECHO This goes to file2
         ECHO This goes to file1 > file 1
         ECHO This goes to file2, again
        ) > file 2

* Added a kind of old allocated ESTR structure reuser, that avoid reallocating 
  new estr structures. \(Saves up speed\).

## Sunday 27th, October ##

* Some bug fixes, including a bug that appeared with **%~A**.

* Added primary support of **FOR** loops \(ie. simple for loop without 
  options\).

## Friday 13th, December ##

* Solved some bugs in libDos9 \(a hazardous non initialized var\)

* Added support **FOR /F** loops with files as input.

## Thursday 2nd, January 2014 ##

* Corrected **Dos9\_ScriptCommand.c** bugs in which the delayed expansion was 
  not executed even if it was enabled.

* Corrected some manual page

* added some translated pages

* added new **make** system.

* added expressions \(both **interger** and **float** mode\) for the **SET 
  /A** command.

* added **FOR /F** loop support with string as input.

* added support for top-level blocks.

## Thursday 14th, January ##

* added final support of **FOR /F** including the use of command outputs as 
  **FOR** input.

* added **DOS9\_SEARCH\_NO\_CURRENT\_DIR** which does not include the pseudo 
  directories '..' and '.'.

* corrected a compatibility bug with **cmd.exe**: **DIR /b** returned the 
  pseudo directories '..' and '.'.

* corrected an expansion bug with **%%~a** \(and similar var because the 
  interpretor missinterpreted the command if, for example **%%~ax** was badly 
  expanded if **%%x** was not defined\). Now, the choosed varaible is the 
  largest match defined.

* corrected bug with simple **FOR** processing.

* added partial support of **FOR /R**. \(Note: this is provided for 
  compatibility purpose, and that new scripts should not use theses switches 
  any-more.\)

* added version information as a header file, making version management 
  easier.

* added a function to be executed automatically on exit.

* some minor bug fixes.

* some manual pages enhancement.

## Wednesday 15th, January ##

* fixed a bug that prevented both **FOR /R** and **FOR /D** to be executed the 
  right way.

* fixed a bug with use of **.** in file searches.

## Friday 17th, January ##

* Fixed a bug that caused some particular redirections to be misinterpreted, 
  particularly, in blocks **\(echo test>NUL\)** triggered an error, because 
  the output was interpreted to be a redirection to file **NUL\)**. This has 
  been solved, and both '\(' , '|' and '&' operators are know prioritary.

* Modified version information management. Now version are numbered in the 
  following way: **YYYY.major.minor\[tag\]**. Where :

  * **YYYY** : Is the year the version was released.

  * **major** : The major version of **Dos9**.

  * **minor** : The minor version of **Dos9**.

  * **tag** : An optional character, meaning :

    * **d** : Developer version.

    * **b** : Beta version.

* Fixed problem with broken make.

* Enhanced features of **FILELIST\*** functions of libDos9. Search is now 
  quicker. It also resulted in better execution times of the **FOR /R** 
  function \(even though still deprecated\).

## Monday 20th, January ##

* Corrected a but that caused line like **:: comment & command** to execute 
  the command **command**, unlike **cmd.exe**'s behaviour.

* Added **REM** command and comments manual page.

* Fixed broken make that did not build **DUMP** command.

* Added endianness support to **DUMP** command.

* Behaviour of **Dos9** is now the same as **cmd.exe**'s one towards block.

* Fixed a bug that required both **@** and **:** signs to be at first column.

* Fixed a bug that prevented redirection to be executed in a top-level block.

* Added copyright notice to all manual pages.

* Fixed a bug with an added extra space with redirection placed at end of 
  input line.

## Thursday 23th, January ##

* Fixed a bug with the **TITLE** command. The **TITLE** command set a title 
  that was the whole command line \(including **TITLE** statement\).

* Fixed a bug with the **FILELIST** features. It now works as expected with 
  both '/' \(filesystem root sign\) and '\[driveletter\]:/' with windows.

## Friday 24th, January ##

* Started working on an enhanced version of **TEA** text preprocessor.

## Saturday 1st, February ##

* Final version of **TEAv2**. Added support for both **HTML 5**, **HTML 
  4.01** and **xHTML**. Others formats have been dropped.

* Fixed a bug with the parsing of command line parameter. If, the final 
  parameter was enclosed in quotes \(simple or double\), it resulted in 
  undefined behaviour.

* Fixed a bug that prevented user from include pipes in **FOR /F** command 
  input.

* Enhanced pipe features.

* Fixed a bug that caused the following message

        Error : Unable to release mutex

  to be printed at exit, due to an undefined behaviour with **atexit\(\)** 
  function.

## Friday 7th, February ##

* Fixed a bug of **SET /P** subcommand. The bug caused a SEGFAULT to be raised 
  on execution.

* Fixed a major bug that prevented command search to be executed normally, it 
  returned the shortest match available instead of the largest available one.

* Added an error message if the **SET** command is unable to set environment 
  variable.

## Wednesday 12th, February ##

* Fixed a bug of **SET /P** subcommand, that didn't not removed the carriage 
  return at the end of the input.

## Thursday 13th, February ##

* Found a bug that occurs when using **CD** command from inside a batch 
  script, if the path to the script given is relative, **Dos9** tries to open 
  it in the new current path, and fail, or execute a different script 
  depending on circumstances. This is to be fixed in next release \(that will 
  include a bunch of improvements, like **CALL**, I hope\).

## Friday 14th, February ##

* Started working in version **2014.0.8**, a version that will include more 
  features, \(including use of intelligent help browsing, and improved command 
  searching \(through a own procedure, instead of what was used previously\).

* Fixed a bug with multiple lists in **TEA** html mode.

* Added own function to search files in path. It is not used everywhere 
  though.

## Friday 21th, February ##

* Added support of new threaded function, through a particular header.

* The issue of uncontrolled sub-threads that continued to be executed was a 
  major concerns, this is fixed thanks to the new thread functions.

* Solved some errors that occurred when forcing binary input. A few too 
  hopeful assumption were corrected, so that the interpretor will not fail if 
  a binary file \(e.g. randomly generated bytes, such as executables\) is 
  given as batch script, it will just printf a few \(or more\) errors messages 
  at the prompt.

## Monday 24th, February ##

* Solve a bug that prevented correct **%ERROLEVEL%** values from being 
  correctly used, it used to be ignored when using internal commands.

* Decided of a change in the way to deal with variables, in order to enable 
  more compatibility between **Dos9** and **CMD.exe**. The changes resides in 
  the way var and special vars are parsed.

  On the one hand, to make the difference between the two kind of variables, I 
  decided the only way to denote a special var \(ie. like **%%A**\) is to 
  prefix it with two percent. Except for variables like **%0, %1** and so on, 
  which can be accessed with a single **%** for compatibility purposes. This 
  new conventions provides more stylished script and prevent name clashes, 
  \(ie. unexpected behaviour caused for exemple by the following code\) :

        ECHO %1 test%
        :: since spaces in variables names are valid, the result can
        :: be unexpected depending whether "%1" or "%1 test%" are
        :: expanded first.
        

  On the other, the only way to specify environment variables is the 
  conventionnal way, with single **%**. Note that this behaviour has also 
  changed, undefined variables will be replaced by a void string \(they'll be 
  just stripped from the output\).

  Finally, in some cases, using **%a** to specify the special variable will 
  work either, but well, it can just happen on a very few cases, so that it is 
  preferable not to use this notation.

* Changed **Dos9** behaviour towards **%0, ..., %9** variables. Those which 
  are not explicitelly specified at startup will be filled with an empty 
  string, and will expand to the empty string.

## Thursday 25th, February ##

* Finalized behaviour change for variables. Singles **%** are now split from 
  the input at parsing, exception made for the special variables **%0, ..., 
  %9** for which the use of a single percent is still valid \(for 
  compatibility purposes\) as stated previously. This prevent users from using 
  single '%' to denote a special var other than these specified previously.

* Fixed a bug that made **SET /P** subfunction to return inconsistent 
  **%ERRORLEVEL%** codes. In fact, it was the reverse of normal behaviour, 
  that is :

  * Returning **-1** on error.

  * Returning **0** on success.

* Added an example of batch powered by Dos9, a multifunction caculator using 
  both floating point arithmetics and integer arithmetics.

## Thursday 6th, March ##

* Changed the behaviour of the function which decide wether the command is 
  multiline or not. It now correctly handles parenthesis that are not 
  multiline. For example, the following code used to be expected to continue 
  on next lines :

        echo(some test&if 1 equ 1 echo some other test

  However, this behaviour is not actually resolved, indeed, some error might 
  occurs \(in some very special case\) if the previous is run. This is still 
  to be fixed.

* Added more compatible version of **ECHO** command. The command now tolerates 
  various non-mainstream syntax \(ie. using other characters than '.' to force 
  print\). The following variants are accepted :

        echo!
        echo"
        echo#
        echo$
        echo%
        echo&
        echo'
        echo(
        echo)
        echo*
        echo+
        echo,
        echo-
        echo.
        echo/
        echo[
        echo\
        echo]
        echo^
        echo_
        echo`

  Most of these syntax are however not recommended, because they can cause 
  obvious syntax errors, and are only provided for compatibility purposes.

  The characters that were given are those specified by the **ISO-C 90** 
  standard, so that some locale may provide additional characters.

* Switched to **Autoconf** build system. This allows more standard builds, 
  with **GNU** build toolchain. It can be compiled through a **\*NIX**-shell 
  typing:

        ./configure
        make

  The install target is not supported yet. It also does not use **Automake**, 
  since it is hard to see the point of writing awful Makefile.am in order to 
  produce a Makefile that can be written by hand.

## Friday 7th, March ##

* Started to work on a safer block determination. This should not be to 
  difficult to obtain.

* Started to refresh a large part of the core, which includes rewriting what 
  were called modules, and are now just outdated piece of code. I hope those 
  changes to be functional within a short delay. It is mainly about getting 
  rid of old and ugly pieces of codes i've been writing about two years ago. 
  Some function have also been transfered to libDos9, this is limited however, 
  since Dos9 is not stable enough to get it in a whole library.

## Saturday 8th, March ##

* Added brand new parser, and also, brand new file reader. The new 
  implementations are much more safe and elegant. Lots of repetitions in the 
  code have be gathered into singles function to make it more maintainable.

* Silenced **Dos9\_Jump.c**, but hoping to get it works within a short time.

* Added new string search based that take account of escaped-characters \(ie. 
  Characters preceded by '^'\).

* Lots of bugfixes, particularly with the new parser and reader.

* **Dos9** is much more unstable than it was, but it is to be fixed quickly 
  since new version are easier to maintain.

* Changed behaviour of function than are used to get command-line arguments. 
  It already did line delayed expansion, but is include now unescaping \(ie. 
  removing '^'\). Thus some syntax have became valid, such as :

        echo ^!test^!

  This will output **!test!**, without expanding the variable, even if 
  **test** is defined.

  It is also important to note that, syntax with escaping and with quotes are 
  **strictly** equivalent. As an example, take the following code :

        if foo^ bar equ "foo bar" echo YES

  Using, **Dos9**, the code will output **YES**. However, **cmd.exe** will 
  not. It as been chosen to promote the first syntax since it is more easy to 
  handle and far less tricky than escaping characters with **cmd.exe**, which 
  require an almost random number of '^' to escape some character.

* Optimised **Dos9\_RunBlock\(\)** function.

## Wednesday 12th, March ##

* Changed behaviour of the thread functions of libDos9. The **THREAD** 
  structure now refers to the thread ID rather than to a handle to that 
  thread. This new behaviour make it possible to work with thread without left 
  a handle on this thread opened. It also enables the stack to contain 
  **THREAD** structures on both **\*nix** and **windows**.

* Added time-out to the Dos9\_WaitForAllThreads function. This is useful in 
  case of deadlocks or in case of thread that does not terminate.

* Added Dos9\_AbortAllThread function, that kills all remaining thread \(only 
  those that were launched through Dos9\_BeginThread\)

* Added Dos9\_AbortThread function, that kills a thread.

* fixed a bug in the thread library that sometimes causes Dos9 to wait 
  indefinitely, because function Dos9\_WaitForAllThread and Dos9\_EndThread 
  sometimes deadlocked, in a random basis.

* Re-enable **GOTO** function, that works now \(even with cross file 
  argument\).

* Added **TEXT-ANSI** target to the **tea** text processor. It enables 
  creation of colourized output using ANSI escapes code. the use of this is 
  native in **\*nix** and requires ansicon in **windows**.

* Fixed a bug that caused infinite loop if the file read was no more 
  accessible. It now returns and just prints error message.

* Fixed a bug causing **eof** not to be detected in some circumstances.

* Fixed a bug that caused an error to be printed in the case that a script 
  that was loaded with the **GOTO** command contained a **CD** command so that 
  the file could not be retrieved because it was kept with a relative path.

## Thursday 13th, March ##

* Fixed bugs with the run functions. The use of **program || goto error** to 
  perform feature test is avaliable for both windows and \*nix.

* Fixed bugs with **Dos9\_SplitPath** command in \*nix.

* Added a search in **%PATH%** and **%PATHEXT%** \(only in windows\) before 
  running any command.

* Added a redirection for command that have **.cmd** or **.bat** as extension. 
  Those files are now executed by a sub process of **Dos9** instead of being 
  loaded by **cmd.exe**.

* Fixed bug with **Dos9\_GetFilePath** function. It prevented executables that 
  were in one of the **%PATH%** directory to be found if a folder with the 
  same name was in the same directory.

* Fixed bug with the **Dos9\_FileExists** function from libDos9. It sometimes 
  returned true for files that where in the path though not in the current 
  directory.

* Fixed a bug with several encapsulated blocks. The previous parser did not 
  searched for block after a block was solved \(this is is now corrected\)

* Improved block support by providing more routines and by making the code 
  more efficient.

* Fixed a bug in **Dos9\_ExpandVar** function that was introduced build ago 
  when rules for expansion changed. I'm affraid not to have seen it before.

* Fixed a bug with **Dos9\_EsCpyN** function in libDos9. If the functions with 
  0 as iSize argument, although the function is expected to produce a void 
  string, it failed in windows, thanks to microsoft's crt implementation, that 
  throws a SIGSEGV if the last parameter of **strncpy** is 0.

* Fixed a bug with **FOR** command. The tokenizer did not behave like it is 
  described in the documentation : If several delimiters were encountered in a 
  raw, they were not skipped.

* Fixed a bug with the **ECHO** command. The prompt line \(ie. **DOS9 
  ...>**\) was displayed whenever the **ECHO off** flag was set, on direct 
  input mode.

* Fixed a bug that caused some commands to print error messages on **FOR** 
  commands. Most notably, the **FIND** command \(or at least, windows's 
  implementation\) fails if there is no space at end of line, so it added 
  automatically now.

* Fixed a bug with **SET /A** subcommand. It prefixed variable name with a 
  space, making the result inconsistent.

* Made the hlp to work again, without problem, since version **0.7** and the 
  deep changes made into **Dos9** core to get something more modern.

## Sunday 16th, March ##

* Started building a **x64** version of Dos9. I experienced troubles because 
  of the lack of **x64** version of **MinGW**. However, I managed to get a 
  distribution of mingw-w64, the **MinGW** compiler adapted for **x64**, in 
  the TDM-gcc. The install of **libintl** \(and libiconv, on which libintl 
  depends\) must be done by downloading packages from GNU ports, and do some 
  tricks to get it compiled in the x64 version. This is actually difficult to 
  build, and unstable as a did not perform further tests.

* Started profiling the **Dos9** code base, looking for making **Dos9** more 
  fast. The use of **gprof** has brought several interesting analysis. On the 
  one hand, I can't get explanation why is **cmd.exe** faster for long files, 
  although if both are run at the same time, **Dos9** perform about twice as 
  much commands by second. The things to be updated are:

  * **Dos9\_EsInit** and **Dos9\_EsFree** function are far too expensive. It 
    sometimes consumes **10%** of the global time-run, thus, we removed parts 
    of code from the **libDos9** library.

  * **Dos9\_GetCommandProc** is far too expensive. I'm currently looking for 
    an alternative, such as hash function. I haven't found a good one yet 
    \(however\), and i will probably write it by myself.

  * I'm also to optimise the execution times of **Dos9\_String.h**. Those 
    functions are almost ubiquitous in the code, so that large parts of code 
    will benefit from better execution rates. I'm especially targeting 
    **Dos9\_SearchChar** and **Dos9\_SearchToken**, that account for a large 
    share \(about 10% time execution overall\).

  All those test have be made for normal script optimisation, it was tested 
  from a file that implement **goto**, **if**, **set** and **echo command**. I 
  also performed some tests on **for** command, as expected, functions that 
  are the most time consuming are not the same. Though, the functions i listed 
  before were also much more time consuming than they need to be.

* Improved efficiency of **Dos9\_String.h** and **Dos9\_Estr.c** from the 
  **libDos9** library. Also disabled some piece of code that ran thread in 
  some functions, that basically made them slow down. **Dos9** now achieve 
  almost equivalent performances in **for** loops \(about 100 lines/s less 
  than **cmd.exe**, without further optimisation\), it also reach got 
  execution rates at script level \(with about 3250 lines/s while cmd.exe runs 
  at 2720 lines/s on average\). It is surprisingly good because I did not even 
  finished optimisation yet, so much better performances can be expected.

* Fixed a bug of **IF** command. The **lss** comparison operator was 
  interpreted as **leq**.

## Thursday 20th, March ##

* Started comparisons between **GCC** optimisation levels.

* Fixed a bug introduced in the function **Dos9\_SearchLastToken**. It appears 
  that, on windows, the code runs faster using **-O2** than using **-O3** 
  optimisation switches, this might be caused by processor caching, but 
  however, this should not be expected to have the same effect on variouss 
  platform however. I ended up optimisation operations there, since the 
  functions used by gprof account for about **70%** of the execution time, so 
  that I'm not sure it is reliable now. With **gprof** version, i've be able 
  to achieve speeds of about **3700 l/s**, so the result are expected to be at 
  least double. In fact, by experimenting, I got only about **4000 l/s**, 
  which it the speed of **cmd** on my computer when it consumes about 80%-90% 
  of the cpu, in random occasion, because cmd.exe's has really random 
  performances. Instead, **Dos9** is limited to approximately **25%**.

## Saturday 23th, March ##

* Fixed a bug in **Dos9\_SearchLastChar** function.

* Fixed a bug with redirection that was not right dealt with. **Dos9** did not 
  check whether several block are in a row on the same line.

* Added some functionalities to the **cmd/hlp.bat** script, which is meant to 
  replace old-fashioned **hlp** manual page viewer. It is basically designed 
  to act as a manual page manager rather than just a viewer, by providing 
  interfaces to build manual trees, and to get manual tress from the 
  repositories at **dos9.org** \(this is to be implemented later\).

* Changed names of the manual-pages subdirectories, they now match up with 
  traditional \*NIX-like local names that are widely used. Note that only 
  useful locales should be implemented \(at most one for every language\).

## Tuesday 25th, March ##

* Implemented replacement for old **ENABLE/DISABLEDOS9MODE**. Instead of the 
  variable, **Dos9** provides the **CMDLYCORRECT** options that can be set 
  through **SETLOCAL**, and that enables more compatibility features for 
  **cmd.exe**.

* Option **CMDLYCORRECT** now affects **FOR** loops: If the option is set, 
  then all blank lines are to be stripped for the output.

* Changed switch to specify part of lines that are not constituted of switches 
  but by text. It is now **//**, a bit like \*NIX's **--**.

## Wednesday 26th, March ##

* Added a short internal documentation to get help for internal functions. 
  These are however much tinier that the full documentation given in **HLP**. 
  This is voluntary, to fit in the executable.

* First implementation of the **CALL** command is now working. This is 
  somewhat blurred because i've not written the full man page now, but it 
  seems functional.

* Fixed bug in Makefiles.

* Fixed a file from libDos9 that still used old name **CALLSTACK** instead of 
  stack.

* Found out that in some cases, **tea** breaks unicode sequences by intruding 
  some line feed in the file, This remains to be fixed. This was actually 
  fixed quickly.

* Fixed a bug that cause **tea** to loop infinitely if a word turned out to be 
  to wide to fit on a single line. This is now fixed and long words are now 
  split in multiple lines.

* Fixed numerous bugs introduced by use of various encoding in the 
  documentation, that is, some file were not built by **hlp** because iconv 
  was not able to convert file from erroneous encoding. This has been fixed 
  and all pages builds up well with **hlp**.

* Added a couple of manual pages. It is also combined with new pages and 
  translations.

## Wednesday 2nd, April ##

* Implemented aliases within Dos9

* Added **ALIAS** command.

* Improved robustness of **Dos9\_AddCommandDynamic**.

* Fixed some bugs with **CALL** function that was not really functional. It 
  works much better now, but the features have not been all tested yet.

* Fixed a bug that caused **%0** not to be set to the correct value by the 
  **CALL** command. Now, the behaviour is the following:

  * if a **label** was given, **%0** contains this label.

  * if no **label** was given, **%0** contains the file name.

## Tuesday 3rd, April ##

* Updated build system, so that building **Dos9** can allmost be done without 
  user intervention. It's as simple as typing the following line:

        make

* Switched to version **2014.0.9**, because **dos9** is becoming pretty 
  develloped now.

## Monday 7th, April ##

* Fixed numerous bugs on the **GNU/Linux** version. Before that update, it 
  would have been fairly difficult to make it work. I posted only fixes for 
  GNU/Linux, but very few incompatibilities can be expected for BSD based 
  operating systems \(and anyway, the only BSD based os i've got is NetBSD, so 
  that compatibility may not be achieved for other versions. The major fixes 
  included are :

  * A fix for the **autotools** build system, indeed, the old 
    **configure.ac** did not appended needed libraries \(for examples, there 
    was confusions for **libintl**, that is included in **GLibc** on 
    **GNU/linux**\). I think i'll consider choosing a better build systems, 
    because in facts, **autotools** adds endless complications even for 
    building quite simple code. The most Annoying drawback is that in fact, 
    you can't use **autoconf** without using **automake**, otherwise, some 
    bugs are introduced that you'll never hear of reading the documentation. 
    Nevertheless, we don't need using **automake** to generate Makefile that 
    we could write, especially when the output Makefile is about hundreds of 
    KiB, and is constituted of almost hacks to make it work with **make**. 
    Thus, it's a bit like using a program to produce garbage. **autoconf** 
    provides lots of interesting features, but these advantages are superseded 
    by its drawbacks. In particular, the fact that it does not meet the UNIX 
    conception standards \(e.g. each program should do only do one thing, and 
    do it the best\), so that the dependencies between apparently distinct 
    **autotools** programs make the developer to use all the **autotools** 
    programs.

  * A fix for the **Dos9** code itself. The last revisions of **Dos9** 
    included a lot of features that had not been tested on \*NIX operating 
    systems. So that numerous incompatibilities were introduced along source 
    code modification. Mainly, the **thread** part of **libDos9** had been 
    left totally untested on real system for versions. I apologize for that, I 
    should not have been waiting for such a long time to upgrade. So, fixes in 
    the code that have been made are:

    * Make wrapper around undefined symbols coming from windows like 
      **stricmp** \(**strcasecmp** is used instead\).

    * Fixed bugs from **libDos9/threads**, It caused double free exception for 
      some errors.

    * Fixed used of **strupr** in **tea**. In fact, the symbol for **strupr** 
      that was intended to be used on **GNU/Linux** was used on **Windows** 
      platforms instead.

    * Fixed incompatibilities in **libDos9/file**. In fact, default routines 
      for \*NIX used the functions **fopen** to check whether a file existed 
      or not. The bug was introduced because in many \*NIX systems, 
      directories are indeed files that can be opened. **libDos9** now checks 
      for regular files using the **lstat** function instead.

    * Fixed incompatibilities with environment variables. This issue was 
      caused by the fact that environment variables are case-sensitive for 
      \*NIX operating systems while they are not for Windows systems. In fact, 
      **Dos9** already capitalized variable names when variables were set, 
      however, similar feature was not provided for expansion. This is now 
      fixed.

  * Fixes on other files, \(I mean, on files that are not required in order to 
    make **Dos9** runing\). Those fixes include:

    * Changed the name of the **Dos9** executable from **Dos9** to **dos9**. 
      This change will have no effect on windows, but it is usual, however, to 
      have command executable names in lower characters. I may implement a 
      feature for **GNU/linux** that ignore case for the command line. 
      However, I now recommend using uncapitalised characters for command 
      name, if you need compatibility, of course.

    * Fixed a bug with the translation system. It used to scan file 
      **dos9/lang/Dos9\_Help.c** instead of file **dos9/lang/Dos9\_Lang.c**.

    * Fixed a bug from **Dos9\_Auto.bat**, the current version dit not 
      included the path **%DOS9\_PATH%** in the **%PATH%** variable, that was 
      problematic for \*NIX systems, however, the **Dos9** executable filename 
      should be looked up by the program itself, rather than being included in 
      **%PATH%**.

* Changed the way libraries are built. They are now build from within the 
  current direction, and they are located in **./lib** and headers for 
  libraries are located in **./include**.

* Fixed a bug in Makefiles that caused the manual pages to be copied in a 
  wrong directory \(ie. **./bin/share/man** instead of 
  **./bin/share/man/man** that was wrong.

## Thursday 10th, April ##

* Discovered a strange bug with pipes. This bug appears when input have 
  several lines, when the pipe is closed, the input is not restored \(or, at 
  least, the input is not split from **stdin**\). In fact, this should not 
  occur since when the pipe is no more redirected, there is no more input 
  left. This is strange though, as this problem does not happen with 
  single-lines input that appears to work fairly good. It appears that this is 
  caused by buffers that are stored internally in the kernel of the operating 
  systems. A solution that I might consider is using regular files \(instead 
  of pipes\) to produce somewhat of a pipe effect, because I haven't actually 
  found a way to override the problem.

* Fixed a bug with the **Dos9\_ParseOutput** function. It wasn't possible to 
  specify **2>&1** and **> foo** simultaneously, so, you it was not possible 
  to specify a redirection for **stdin** and **stdout** with **truncate** 
  attribute.

## Monday 14th, April ##

* Added some corrections that make the pipe function quite well on both 
  **GNU/Linux** and **Windows** architectures \(I also tested on **NetBSD** 
  and it worked pretty well, without further tests however\).

* Added a few fixes on languages, and I'm starting adding new messages for the 
  **file** commands.

* Checked build on NetBSD. I've found out that **Dos9** conforms with 
  **POSIX.1-2001**. Thus, On some platform, if you want to build if, you may 
  specify a configuration that defines the **\_POSIX\_C\_SOURCE** macro, that 
  is, type the configure line :

        ./configure CFLAGS='-D_POSIX_C_SOURCE=200112'

  However, The NetBSD headers does not conform to **POSIX.1** and perform 
  wrong function exposures, so that if you use, it, you might need to specify 
  **\_NETBSD\_SOURCE** macro.

## Thursday 17th, April ##

* Added some translation message in the locale.

* Added new manual pages and lots of fixes in the manual pages.

* Added **SHIFT** command. It can be really easy to manage argument, now, 
  however, I did not preform deep test on the command so that it might still 
  be not reliable.

* Added **/f** switch to **ALIAS** command. This allows user to redefine 
  internal commands and symbols, what was not possible previously. I decided 
  to let user override internal commands because I found it to be an 
  interesting thing to hack around, allowing to set up replacement commands 
  for some batch that needs enhanced compatibility features \(although they 
  should not need such compatibility features\).

* Fixed a bug in **Dos9\_Thread.c**, threads functions were making casts from 
  different pointer sizes, ommiting the pointed object were different. Thus, 
  writing 8 bytes to a location which was supposed to be 4 bytes long, 
  depending on the locations of those data in the executable \(and hence 
  depending on compilation\), it could cause really dangerous errors, such as 
  stack corruption for example, in some rare cases. This is now fixed, 
  preventing a rare crash to actually occur.

* This is the final build for at least a few months. I'll be very busy in the 
  next few month, but I hope i'll be able to submit new fix starting in the 
  summer holidays.

## Saturday 20th, April ##

* Fixed a bug that caused **Dos9** to crash if either **%PATH%** or 
  **%PATHEXT%** \(only for windows\) were not in the command environment.

* Corrected a bug with **tea** in **html** mode. The parser did used to escape 
  the reserved characters **>** and **<** but did not care of **&**. This bug 
  is corrected, enabling **html** codes to work perfectly well. I hadn't 
  noticed it until yet because most recent browsers do not care about such 
  errors, preventing error to be easilly triggered.

* Fixed omission of **ansicon** on the **Dos9\_Auto.bat**, which is launched 
  at startup.

## Saturday 14th, June ##

* Following advices of guys for dostips.org, changed the delimiters and the 
  way quotes are handled:

  * The available delimiters are the following **\(space\),;\(tab\)**. This is 
    now fully compatible with **cmd.exe**. I also introduced functions in 
    order no to take care of some of them \(**,;**\) since they may be used by 
    some programs for switches. \(The first example I have is **gcc**, and 
    options like:\)

            gcc -Wl,import

  * Changed the way quotes are handled. Quotes have now precedence over 
    conditional operators \(**|&**\) and command blocks \(**\(\)**\). This 
    enables to make statements more secure using quotes. The new behaviour 
    also conforms to cmd.exe behaviour. Typically, the following code :

            IF foo==foo echo  ") else ("

    was understood differently by **Dos9** and **cmd.exe**. Now, the **"\) 
    else \("** is considered to be escaped, and is no more interpreted as a 
    subcommand of **if**, as it did before.

  * Chosen a standard way to handle quotation marks, an to cut parameter. In 
    fact, any delimiter that is between two quotation marks is ignored. So 
    that parameters are cut on unquoted delimiters, some example of now valid 
    parameters are :

            "simple quotation"
            foo="foo bar"

    and so on and so forth...

    If the interpreter finds an unpaired quotation mark, then, the remaining 
    characters are considered to be between quotation marks. So that, the 
    following examples are equivalent:

            type "some file
            type "some file"

  * behaviour of function to remove quotation marks in parameters have also 
    changed in order to achieve more compatibility with **cmd.exe**. 
    Basically, the algorithm that **Dos9** follows when removing parameters 
    quotation marks is:

    * If the parameter begin with a quotation mark, then remove it, otherwise, 
      stop the algorithm at this step.

    * If the parameter end by a quotation mark, then remove it either. But, do 
      not remove it if the parameter does not begin with a quotation mark.

* Cancelled the conversion of **Dos9** code to wide char. This was indeed far 
  too hard \(it implied modifying almost any piece of code\), and had little 
  advantages \(huge incompatibilities between various platform, particularly 
  for non-c99 function that are obviously required in order to make thing 
  working\). Thus, I decided to make a wrapper over libC functions in order to 
  be able to use utf-8 internally. This way, I keep the code like it is, and 
  preserve compatibility with other platforms \(Windows, Linux, NetBSD, 
  DragonFly BSD, OpenBSD\) and with POSIX. Moreover, this support for unicode 
  may easily be removed for platforms that do not handle utf-8, or those that 
  do it natively.

## Monday 16th, June ##

* Reorganized the source tree for internal commands. Before that, every file 
  of the **command** subdirectory contained several different commands. I 
  found that is was not really practical for maintaining code, the code is now 
  split in files that contains each a different internal command.

* Added a functional **/Q** switch to the **RMDIR** command. However, it is 
  supposed to deal with the **/S** switch, which is not functional yet.

## Thursday 19th, June ##

* I eventually decided to use the GNU toolchain to compile **Dos9**. I 
  previously expressed lots of criticism toward use of autotools, but libtool 
  \(which is par of the GNU toolchain\) is unfortunately the only program that 
  allows developers to deal with libraries \(statically or dynamically 
  linked\) in a platform independent way. This is the best solution I have, 
  but if a newer build systems that enables to make such things emerged, I'd 
  be glad to move to it.

* Changed some source file name because **automake** was complaining about 
  overlapping objects file names. Some of the name are more logical, but, some 
  are not really.

## Tuesday 24th, June ##

* Corrected a bug that prevented local variable \(eg. like **%1**\) to be used 
  as argument with the **call** command, thanks to Jo15 from 
  [batch.xoo.it](http://batch.xoo.it) who reported the error.

* Added **local** target to **Makefile** that generates a local installation 
  of **Dos9** inside the folder **./bin**. It is as simple as typing

        make local

* Added macros from the **gnu gettext** package. Also enabled the use of the 
  --disable-nls switch for configure.

## Friday 29th, August ##

This is the first time I write something in this file for a long time now. 
I've been hacking around Dos9 for a little time now \(haaa, holidays\). This 
is a list of improvements I made during from 24th June to today.

* Changed behaviour of parameter handling routines, valid delimiter are now 
  ",; " and tab. The way doubles quotes are handled changed either. An quoted 
  expression may be constituted of an arbitrary long string that conforms to 
  the following rules :

  * Any delimiter is ignored if it is surrounded by double quotes.

  * If double quote, is directly preceded or followed by an string characters 
    that are not delimiter, this string is part of the parameter.

  * And so on and so forth, until we reach unquoted delimiters on both sides 
    of the parameter.

  Moreover, the quotes are removed if their position conform to the following 
  rules :

  * If a parameter begins with a double quote it will be removed.

  * If a parameter ends with a double quote and begin with a double quote, 
    both are removed.

  * Else, keep the line like this.

* Fixed some autotools options, that where never mentioned under mingw system.

* Fixed incompatibilities with the IF command. Now, the **IF** command returns 
  errors on case of string used as operators for **GEQ**, **GTR** **LSS**, 
  **LEQ** comparants. Moreover, the interpretor is able to handle both 
  hexadecimal, decimal and octal bases. Finally, implemented comparants for 
  floats \(same as integer comparants but prefixed with f\), as a **Dos9** 
  extension.

* Fixed issues of compatibility for the SET command. It is mainly a matter of 
  quotation marks handling, and typically, the issues for both SET /p and SET 
  are fixed, while little issue \(not for simple /a assignments of course\) 
  still exist for the SET /a command.

* Some fixes for the FOR command, now enabling the use of the three numeric 
  bases for all the parameters and preventing overflows in FOR /l loops.

* Modified the FOR command in order to accept filename sets to be given as 
  input for the FOR /F command. This puts more sense on the "usebackq" option.

* Added a custom environment within **Dos9** in order to instaure 
  cross-platform syntax capabilities like use of "=" in variable names \(which 
  is impossible on many systems\), to set "=x:" variables for CD command.

* Corrected a bug with SET command, wich displayed system environment while it 
  was supposed to display **Dos9** custom environment.

* Corrected a bug that prevented the FOR command from getting command input 
  under any \*nix OS \(don't know the actual reason for this, but I 
  reimplemented the code using the \*nix call fork\(\), which is, frankly, 
  much more convenient than tricky systems to communicate between process 
  under windows\). The command redirection now works pretty well on any \*nix 
  system.

* Added a Windows specific new CD command, to be compatible with Windows 
  **cmd.exe** features. The primitive version of CD is still shipped for \*nix 
  operating systems \(concept of disk is a huge non-sense under Unix-like 
  operating systems, because they represent filesystems like a binariy tree 
  which root is "/", and on which filesystems and devices are mounted as 
  directories\).

* Fixed a bug, that always caused wrong pid to be awaited if the process was 
  forked on time through FOR /F command \(with a command input\) under \*nix 
  operating systems, resulting in a mess between commands and commands 
  outputs.

* Implemented new functions within libDos9 in order to quickly sort files 
  matching to some attributes and file not matching in a single function call.

* Re-implemented the TYPE command to get a command compatible with 
  **cmd.exe** equivalent. The result is very closely compatible except for on 
  case of name printing.

* Implemented FIND command as an internal command. It matches closely cmd.exe 
  behaviour, except for some inconsistencies I've tried to address \(limited 
  line length, etc\).

* Implemented the %\* variable, that have been lacking in the Dos9 
  implementation for a very long time \(special var are implemented at least 
  since 2013\). However, there is still little concerns, for example, on 
  Unix-like operating system it is impossible to retrieve the original command 
  line \(arguments are passed separated to the kernel\). Thus, the 
  [Dos9](dos9) tries to construct the line back the best it can, by putting 
  spaces between the arguments. This is only an issue at startup, though, with 
  call, it may not be a problem.

* Changed the version number to **2014.0.9b**, I think the interpretor may be 
  mature enough to think of a real release in a close time.

## Wednesday 3rd, September ##

* Implemented a new pipe system for Unix-like operating systems \(that may 
  have broken the good-old WINDOWS implementation, haven't checked yet\). It 
  uses full power of fork\(\) system call and do not suffer from output 
  truncation due to size of kernel's pipe buffer. Also, both command are now 
  parallelized, gaining significant execution time in comparison to older 
  system. This pipe system does not apply to WINDOWS operating system, which 
  will benefit from a new pipe system in little delays.

* Removed padding of arguments with **"** for external commands, on Unix-like 
  operating systems. Indeed, padding **"** around arguments often cause 
  command to fail \(precisely, make the command not work the way you are 
  intending to\).

* Fixed a little issue with the autotools suite. In some Unix-like systems, 
  the host triplet was not reported to program. That does not matter a lot, 
  anyway.

* Definitely set libDos9 as static by default. It is indeed much more 
  convenient \(no installation needed on Unix-like operating systems\). Some 
  may object that it results in bigger executables. But most of time, size is 
  not really relevant, and it save setting library search path anyway, thus 
  enabling dos9 to be embedded in the a memory stick for example \(And yeah, 
  size ain't too relevant, because memory stick often have size of few GBs\). 
  Furthermore, static linking allows compiler to perform further 
  optimisations, that can't be done with dynamic linking.

* Fixed some bugs with the SET command that did not use the custom environment 
  every time, causing the command to fail.

* Adapted the hlp.bat script to make it work on Unix-like operating systems. 
  The new scripts also uses the shift command intensively.

* Fixed some bugs in translations. Removed the en\_US local which is almost 
  stupid.

## Wednesday 24th, September ##

* Implemented the **MORE** command as an internal command \(why create 
  external executables when it is so simple to add little commands to the 
  interpretor ?\). It includes almost every **cmd.exe** features, except the 
  form-feed expanding features \(never seen it used though\). However, if you 
  build **Dos9** with the option **--disable-console**, you should still 
  encounter minor bugs, due to the lack of console capabilities. Finally, I 
  thought about replacing **MORE** with **TYPE** when building with 
  **--disable-console**, but it would be obviously sad not to benefit from 
  this far better and new command.

* Implemented a special stream translation system \(for streams like **NUL**, 
  **CON**, and so on and so forth\), to get Unix name of their counterparts. I 
  did not implemented the translation for all streams I know, though, but it 
  won't be to annoying to be added.

* Corrected a few bugs for Unix-like systems.

## Tuesday 2nd, December ##

* Corrected a bug within the **IF** command that prevented **ELSE IF** 
  combination to be executed correctly. This was actually caused by a failure 
  to match parenthesis the right way. It was basically making only the first 
  line of the if block to be executed. Now the bug is solved and the result is 
  fully functional.

* Added two features within the **MORE** command that enable it to accept both 
  UTF-8 encoded text and ansi escape codes to be mixed with text.

## Thursday 6th, January 2015 ##

* Did some final arrangements that make **Dos9** ready to release on the 
  GNU/Linux platforms. There is some work left for make it run under Microsoft 
  Windows platforms.

* Fixed a little bug of the **More** command under Microsoft windows. 
  MS-Windows does not return line-feed characters using getch\(\) function but 
  returns untranslated chariot return \(0x0D\). This subtleties was not taken 
  account by the **More** command, so that the enter was inactive.

* Changed the way **Dos9** command line works; Now it's possible to use 
  widespread switches like '/C' or '/K'. The way to tell the interpreter which 
  option should be enabled and which should not through the command line has 
  also changed.

* Fixed minor issues due to the previous behaviour change of 
  Dos9\_GetExePath\(\) that affected both **FOR** command and 
  Dos9\_RunExternalBatch\(\) function.

* Fixed the broken pipe system introduced by the change of pipe system on 
  GNU/Linux \(and most of \*nices\). This is not fully tested though. But the 
  new way of handling pipes permits infinite length for both input and output 
  of commands.

## Tuesday 13th, January 2015 ##

* Fixed an minor issue in the **Dos9\_SetEnv** function that caused some rare 
  bugs that made **SET** command to raise a segfault if it was invoked to 
  remove a variable from the environment. It wasn't that frequent because 
  usually, variable removal didn't worked, due to another bug. This is now 
  fixed.

* Added the **START** command on Windows, That works pretty well, even if some 
  parameters seem to be ignored by windows, such as **/Wait**. The command 
  have few option compared to cmd's version, but, it's a good start point 
  anyway.

* Changed the version number to 214.1b, that mean, it's the beta of the first 
  stable version which is expected to be released within a short time.

## Tuesday 21rd, April ##

* Fixed a minor issue in the error system for the **IF** command, the command 
  used to exit the interpretor upon minor error.

* Added number of new command to deal with files. Among this command, we have 
  **MOVE**, **COPY**, **DEL**, **MD**, **RD** and some others.

* Changed the ESTR syntax. I think it is actually easier to access the string 
  by using a -> rather than an obscure macro. Moreover, it renders the code 
  more simple, it add less symbols.

* Continued French translation.

* New and reviewed man pages. Some manual pages were clearly outdated as some 
  had more than two years although the command changed. To clear this out, man 
  page content as been revised to be more relevant.

* Added a brand new Dos9 extension to the **IF** command. I found pretty 
  annoying that cmd \(and thus Dos9\) lacked support for multiple conditions 
  for a single if \(e.g. logical expressions\). Obviously this could have been 
  done previously by using the **SET** command to evaluate an expression but 
  this was time- and code-wasting. The interpretor currently supports only 
  **or** and **and** logical connectors. These are widely sufficient for most 
  cases, except some rare cases that requires you to have **xor** either. This 
  is not a big concern, it is just about writing a few more code.

  The syntax is pretty simple, but must include blanks around brackets:

  * **expression** or **expression** : True if one of the two expressions \(at 
    least\) is true.

  * **expression** and **expression** : True if both expressions are true.

  * \[ expression \] : Denotes a higher precedence.

  As you can see, the syntax is clear but efficient. You can use test that are 
  provided by the **IF** command :

  * **not**

  * **defined**, **errorlevel**, **exist**

  * **equ**, **neq**, **leq**, **geq**, **lss**, **gtr** and derivatives

  Note that the **IF** command only interpret expressions as such if they are 
  surrounded by brackets, like in this example :

        if [ a equ b ] echo no, seriously ?

## Sunday 10th, May ##

* Some fixes for windows, specially for the CTRL+C handling routines.

## Friday 24th, April ##

* Fixed a few remaining bugs in the implementation of if extended expression. 
  As a example, in some case, an **or** used to be computed as an **and**. 
  These issues are now fixed and the command great.

* Merged tests of the **If** command. In fact, some test were duplicated in 
  different sources, but for maintainability reason, it try to give up with 
  the copy and past approach.

* Corrected an issue of the **TEA** text processor. When producing html 
  output, **TEA** often failed to recognize path that refer to actual other 
  **TEA** based pages and others files. One of the typical issue was that TEA 
  sometimes appended ".html" to URIs \(that already contained an ".html" 
  anyway\). Now, **TEA** also check for protocol prefixes in order to chose 
  whether a ".html" suffix should be appended. Recognised protocols are :

  * **http://**

  * **https://**

  * **mail://**

## Thursday 7th, May ##

* Fixed lots of man pages for the Dos9 project. Also fixed some little bugs in 
  the TEA text processor, dealing with some sort of **\** that where 
  mishandled in previous patches.

* Changed regexp implementation after discovery of some bugs \(eg "test" was 
  not matching "\*e\*s\*"\). The new implementation is less faulty and clearer 
  to use.

* Added a new **/e** switch to the **FIND** command \(to produce somewhat 
  similar to UNIX's well known **grep -e** command\). It enables use of joker 
  expressions on patterns. With this option **FIND** checks that the entire 
  line matches the expression.

## Thursday 2nd, June ##

* Corrected some issues compatibility issue with the newest MinGW version that 
  now defines **\_POSIX\_C\_SOURCE**.

* Fixed a bug with the start command. Apparently, the ShellExecuteEx function 
  does care whether or not the filenames passed to it contains forward slashes 
  instead of backslashes.

* Added some little info message to the **SET** command in order to print the 
  result of the expression when using **/A** slash.

## Thursday 10th, June ##

* Added a wrapper to the **MORE** command to make it display utf-8 text the 
  way it is intended to. Indeed **windows** does not implement implement the 
  fputc\(\) function as specified by the standard and considers that it 
  receive character instead of bytes.

* Fixed a bug of the **MORE** command that caused miscomputation of utf-8 
  characters number.

## Wednesday 13th, Junuary, 2016 ##

* Added support of libcu8, a library designed to handle utf-8 efficiently with 
  msvcrt in windows. This is part of a large ongoing effort that attempts to 
  make Dos9 more internationalizable. To do so, We had to kind short-circuit 
  msvcrt with brand this brand new library. Although still experimental, this 
  works quite great.

* Added new CHCP command to handle efficiently the new libcu8 library.

## Monday, 25th, Junuary ##

* Changed version of Dos9 to emphasize the important changes of Dos9 since new 
  year 2016.

* Added functions to restrict fd inheritance, to make sure the appropriate fds 
  are closed on exec. It is basically usefull for FOR commands.

* Hugely modified the libcu8 to fit with libDos9. It is still an experimental, 
  though, but it works way better now.

* Added some new behaviours in file expansion. Now, it is legal to specify 
  negative offsets during variable expansion. Quickly, negative offsets refers 
  to the absolute value of the offset, counted from the end of the variable. 
  For instance, this is now allowed :

        %var:~-2,-1%

## Thursday, 28th, Junuary ##

* Added an option that allow using switch catenated with commands, such as

        set/p var=question

* Fixed and modified hugely the dump command so that it is way more portable.

## Sunday, 7th, February ##

* Fixed some bugs with the FOR command.

* Fixed some bugs in redirections.

* Fixed little bugs in libcu8.

## Thursday 18th, February ##

* Added the '=' operator for the SET command. The operator do behave a little 
  bit differently from cmd.exe's SET, but it is convenient too. For the 
  moment, libmatheval only supports explicit number anyway.

## Monday 16th, April ##

* Modified the initialization procedure of Dos9. Dos9 can now handle two 
  different startup files:

  * **$HOME/.dos9/Dos9\_Auto.bat** : user-specific startup file

  * **$DOS9\_PATH/Dos9\_Auto.bat** : system-wide startup file

* Fixed some bugs with **SET** and redirections.

* still develloping dos9ize

* Fixed errors with folders containing spaces for Dos9.

## Friday 15th, July ##

* Fixed a little bug with the for command. When the field "delims=;" is 
  specified with **FOR** without "eol=" being specified, then the character 
  ";" is not used as the default end-of-line character.

## Wednesday, 14th, September 2016 ##

* Added PUSHD and POPD commands

* Allow to list variable which match with a prefix

## Friday 18th, October 2016 ##

* Removed the complex initialisation model set up the **16/04/2016** in favour 
  of a single \(somewhat read-only\) **Dos9\_Auto.bat** initialization script 
  that calls automatically local and global custom initialization scripts.

* Worked a lot to improve the binary tree, in order to conform to unix 
  installation standard and windows, by the way. This is near to being ready.

* Modified the **TYPE** command, adding the following features :

  * The file names are now echoed thought the standard error output. This new 
    behaviour allows sorting out easily file names and file contents. By the 
    way this is also more conformant to **cmd.exe**.

  * If no filename is specified, the **TYPE** command gets it input from the 
    standard input, acting quite the same as more.

  * Few documentation updates.

## Tuesday 26th, October ##

* Fixed configure.ac bug preventing autotools from properly detect BSD based 
  OSes.

* Lots of fixes for the libcu8 library, which was not working properly on 
  32-bits platform. The lib now directly asks the location of function using 
  the kernel instead on relying on pointers given by the libC.

* Some minor fixes for Dos9 in general.

* Fixed a little hlp bug

## Wednesday 26th, October 2016 ##

* Rewrite Pushd and Popd commands.

* Fix some commands help.

## Thursday 27th, October ##

* Change location of gettext files under unices to match the usual file 
  layout.

## Friday 28th, October ##

* Fix some compilation errors.

## Sunday 30th, October ##

* Improve pushd command and add documentation.

## Tuesday 1st, November ##

* Fixed some compilation errors with some the stat and findnext functions.

## Wednesday 9th, November ##

* Fixed some minor errors with config.h \(basically expansion of datadir\)

* Fixed errors.

## Wednesday 23th, November ##

* Fixed compilation error in Dos9\_Lang.c.

* Add compilation command in BUILD.readme.

## Sunday 4th, December ##

* Fixed some major bugs submitted by Teddy Astie, for unices. Including :

  * Errors in parsing lines containing nested for loops when braces are not 
    explicitly specified. eg:

            for /l %%A in (0 1 10) do for /l %%B in (0 1 10) do (
               echo %%A %%B
            )

  * Cleaned up zombies processes that were not wiped from kernels buffer since 
    Dos9 never explicitly specified to throw the data out. Basically, this 
    behaviour is particularly shown when repeating for loops. eg:

            :loop
            for /f "delims=: tokens=1,2,3" %%A in ('echo this:is:a_test') do (
                echo %%A %%B %%C
            )
            goto :loop

* Changed Dos9 behaviour when getting a SIGINT on Linux. Depending on whether 
  a user input or a script is being executed, the interpretor choose to cancel 
  the command or to exit.

## Monday 5th, December ##

* Fixed a bug with FIND command, the case sensitive and insensitive features 
  were swapped

## Wednesday 7th, December ##

* Correct some words in French \(fr\_FR\) manual.

## Monday 30th, Junuary 2017 ##

* Fixed little errors with **SET** and **/a:i** switches.

* Fixed delimiters errors for parsing input and conditional operators.

* Fixed errors with gotos, basically omit spaces before labels.

## Wednesday 8th, February 2017 ##

* Fixed some bugs with the move command.

## Thursday 9th, February ##

* Fixed a major bug of the IF command. Before that, it had fuzzy behaviour 
  with blocks that were part of a later command. Indeed, when combined with a 
  command that required a block but which was not enclosed in a block, the 
  line was poorly handled, eg:

        if a==a if b==b (
        echo test
        )

  This example \(and its derivatives\) should now behave the way it is 
  intended to, that is, as if it was specified as :

        if a==a (if b==b (
        echo test
        ))

## Saturday 12th, February ##

* Fixed minor bugs with the **START** command.

* Fixed many manual pages.

* Fixed if dos9 extension bug.

## Monday 13th, February ##

* Fixed libcu8 so that it runs flawlessly under windows XP. The bug consisted 
  of a CRITICAL\_SECTION that was wrongly initialized. A second bug involving 
  libcu8\_closedir\(\) as been fixed.

* Fixed errors with the hlp script.

## Wednesday 15th, February ##

* Fixed a lot of memory leaks.

* Fixed libcu8\_closedir\(\) function. Indeed, the function did not close 
  directory in a correct way.

* Fixed libcu8\_dup\(\) functions to handle standard input the right way.

## Friday 17th, February ##

* Fixed libcu8 so that libcu8 ignores invalid utf-8 bytes sequences, instead 
  of returning errors.

* Fixed the FOR function freeing function.

* Fixed some manual pages.

## Thursday 16th, February ##

* Update hlp.bat and man.

* Fix a bug with some libc when display the current directory \(with Echo 
  on\).

## Wednesday 22th, February ##

* Added a new feature to the **FOR** command that allows using regular 
  expressions with simple **FOR** loops. \(eg. such syntaxes are now correct\)

        for %%a in (*.exe) do echo %%a

* Fixed an bug with the **GOTO** command that prevented error messages from 
  being displayed.

* Fixed error of the **FOR** commands that wrongly omitted **goto** effects or 
  **exit /b**.

* Modified **FOR** manual page according to the new features.

* Added **/b** switch for the **START** command.

* Added new feature to **START** command so that it handles empty program name 
  in a way similar to what cmd does. \(ie. running an instance of cmd /c\).

* Added styles to manual pages thanks to styles-sheets provided by Xenoxis.

* Changed libDos9 functions to search files with a totally new implementation.

## Saturday 25th, February ##

* Fixed some errors with libcu8 that was unable to behave properly using pipe 
  as it sometimes blocked on input.

* Fixed wrong behaviour of the **%\*** variable which contained all the 
  command line, instead of containing only parameters.

* Fixed errors with propagation of environment variables during application 
  launch affecting batch and external command launch.

## Tuesday 28th, February ##

* Fixed libcu8 handling of pipe that did not allowed interaction with programs 
  such as **darkbox**.

## Thursday 16th, March ##

* Fixed some error of libcu8. Sped up the library by determining when charset 
  conversion is really necessary \(ie. do not convert blindly text from utf-8 
  to utf-8\).

* Fixed some unspecified behaviour with the FOR command. Indeed, when given a 
  command as input, the for command would not way for the process to complete 
  before continuing in case of encountering **GOTO**s or **EXIT /b** command. 
  This led to an unnecessary "zombie" process and could easily lead to 
  unexpected behaviours since no synchronisation interface was provided by 
  Dos9.

  This issue has been fixed by forcing Dos9 to wait for the process launched 
  by **FOR** to exit before resuming execution. Note that it doesn't change 
  the overall **FOR** behaviour, that is, both processes are ran 
  asynchronously \(ie. at the same time\), which is different from cmd 
  behaviour.

## Tuesday 21th, March ##

* Fixed some typos that caused some minor bugs depending on configuration.

* Fixed a minor bug of the **DIR** command that was not ignoring case when 
  dealing with disk letters.

* Fixed a misimplementation of the **START** command when not using libcu8 
  \(nor Linux\).

* Made the **/b** switch working with unices.

## Wednesday 29th, March ##

* Fixed some error in file search handling \(the origin folder of a static 
  string was not added to matches, as if DOS9\_DIR\_MODE was the default 
  behaviour\).

## Thursday 30th March ##

* Fixed a bug with **FOR** command that created more variable that it it was 
  necessary when using a joker **\*** as the final token specifier.

* Fixed bug with **Dos9\_ShowErrorMessage\(\)** function that called the dos9 
  exit function twice, causing a SEGFAULT.

* Fixed the **START** command :

  * Fixed problems with transmission of **Dos9** attributes.

  * Fixed handling of the title parameter.

* Fixed an implementation error which resulted in misinterpreted delayed 
  expansion when variable name started with a number.

* Fixed block parsing systems.

## Sunday 2nd April ##

* Fixed a compilation error on \*NIXes.

## Wednesday 5th, March ##

* Fixed lots of bugs caused by the new parsing system.

* Fixed some errors of the **for** and **call** command.

* Fixed the **TYPE** to make it capable of handling binary files.

## Sunday 9th, March ##

* Fixed the expansion system to behave closely like cmd does. \(ie. made two 
  distinct level of special var expansion, one for the program parameters and 
  one for the other conventional special vars\).

* Changed expansion of special var resulting from a **FOR** to be executed 
  before block execution.

* Added a safe CTRL-c handler on windows.

* Merged po files for Dos9.

## Wednesday 12th, April ##

* Fixed incorrect block parsing that did not handled properly escaped new line 
  characters that resulted in executing commands as if there was actually more 
  commands than there are really.

* Added some error messages and new languages message to be used for CTRL-c 
  handler.

* Fixed many typos.

* Fixed plenty of tiny bugs.

## Thursday 13th, April ##

* Added new system that loads the entire script file at once, instead of the 
  weird old mechanics that consisted in opening/reading/closing script at 
  every new line. This achieve a great performance gain.

* Fixed an error of the Dos9\_SetFdInheritance under unices.

* Fixed the goto command to make it able to deal with label that have spaces 
  inside them.

* Fixed a bug that prevented i10n to be enabled with simple help modules.

* Fixed some manual pages.

## Friday 14th, April ##

* Fixed some interpretation error with the **SET /p** command.

* Fixed conditional definition of \_X\_OPEN\_SOURCE.

* Fixed an enormous memory flaw that took place in the inteval libraries and 
  caused Dos9 memory consumption to increase dramatically when using **SET 
  /a** intensively

* Fixed typos with i18n.

* Removed unnecessary config.h.in from repository.

* Fixed **GOTO** command ignoring bAbortCommad.

* Fixed command **SHIFT** that picked arguments in the wrong local var blocks.

* Fixed **Dos9\_Auto.bat** man page that was in ANSI instead of utf-8.

## Tuesday 18th, April ##

* Added new file searching functions to speed up file search under windows.

* Fixed buffering modes of **TYPE** and **DIR** command to speed up functions.

* Fixed issues of both libinteval and libmatheval in determining delimiters.

## Thursday 20th, April ##

* Fixed errors in unicodes files search functions.

* Fixed **FIND** command for enhanced compatibility with cmd.exe.

* Fixed manual pages.

* Fixed some typos.

## Monday 24th, April ##

* Fixed errors in unicode file searching function and functions.

* Fixed find to make it faster using file buffering potential.

* Fixed the set command.

## Friday 5th, May ##

* Added support for concatenation using '+' with the the **COPY** command.

* Added better support of variable truncating using numbers when Dos9 is 
  explicitly compiled to deal with utf-8.

* Fixed error messages and help messages.

* Fixed manual pages.

## Friday 25th, May ##

* Fixed lots of little bugs

* Fixed handling of stdin with the commands \(especially resetting the file 
  flags after exit\).

* Fixed **DEL** and **RMDIR**.

* Fixed File search functions.

* Changed behaviour of the **/C** and **/K** switches.

* Added support of more than 10 arguments through the use of the shift command 
  and the %+ variable.

* Added WC command.

* Added XARGS command.

* Fixed man pages and i18n messages.

## Tuesday 30th, May ##

* Fixed dir search function for non-unicode and unicode versions.

* Fixed pseudo-directory bug with if exist.

* Fixed rmdir bug.

* Fixed start bug.

* Fixed call bug.

## Friday 2nd, June ##

* Fixed extra newline bug after **echo** off.

* Fixed errors with pipes.

* Fixed **rename** and **del** command.

* Fixed **copy** command.

* Fixed file search bug for vanilla functions under windows.

## Friday 21st, July ##

* Heavily modified the interpretor that no uses threads instead of of 
  separated processes.

* Fix of the set command.

* Lots of bugfixes.

## Sunday 3rd, December ##

* Fixes for path name handling in Dos9\_GetMatchFileList

* Added semaphores to fix SET command.

## Sunday 1st April, 2018 ##

* Added fixes for Dos9\_EsToFullPath\(\).

## Sunday 7th, April ##

* Fixed hlp.bat bug related to the behaviour change of %~pA.

* Fixed bug that caused Dos9 not to append a / after disc in %~dpA.

* Added a /C:MD file to generate html files compatible with pico

## Wednesday 11th, April ##

* Fixed error on handling **2>&1** redirection.

* Fixed Dos9\_FilePath.c error that led Dos9 to check for **file** before 
  using **%PATHEXT%**.

## Sunday 23rd, April ##

* Changed conditional operators and redirections semantics \(ie. conditional 
  operators now own precedence over redirections, just the regular cmd-way\).

* Fixed an error with file search not using libcu8.

* Fixed some typos on english manual.

* Fixed compatibility issue due to msvcrt inconsistent structures name for 
  **finddata** and **stat**.

## Thursday 26th, April ##

* Fixed some manual pages.

* Fixed additional **Dos9\_CloseThread\(\)** bug on unices.

* Fixed memory leak in **Dos9\_InitEnv\(\)**.

* Fixed some **FOR** commands bug using **Dos9\_EsToFullPath\(\)**.

* Fixed some invalid casts in search functions.

## Saturday 29th, April ##

* Fixed a memory leak.

* Changed version to 218.1

* Fixed **Dos9\_RunExternalCommand\(\)** which add a pretty big footprint on 
  the stack, sometimes causing stack overflows with Musl libc.

## Tuesday 15th, May ##

* Added new build system based on femto.

* Fixed text files.

* Fixed a great lot of typos.

* Extended documentation.

* Added the possibility of using unix-style switches with tea due to problems 
  of mingw that mangled the slash of switches.

* Fixed a bug of the **DEL** command. If the required file refers to a dir, 
  the same behaviour as the one used with **DIR** is used so that files inside 
  that dir get deleted.

## Thursday 17th, May ##

* Fixed CTRC-C handling. Sadly the new multi-thread implementation makes it 
  impossible to grab any current directory or modified environment.

## Tuesday 22nd, May ##

* Fixed Mutex locking error in the SET command.

* Modify **GOTO** and **EXIT** to leave **%ERROLEVEL%** unmodified upon 
  execution.

* Added the local variable environment creation via **SETLOCAL** and 
  **ENDLOCAL**.

## Wednesday 23rd, May ##

* Added new manual and functionalities to **START**. When calling internal 
  command with **/b** option, The command is launched as an internal thread.

* Fixed the **CD** command that without argument displayed an error message.

* Fixed an error with file redirection inside the **FOR** command input.

* Fixed set command SEGFAULT error when listing variables. Fixed typos in the 
  manual page.

* Added **ENDLOCAL** manual page.

* Fixed memory leak when duplicating thread environment.

* Fixed parsing errors that misinterpreted **2>&1** as a combination of a 
  redirection and the conditional operator **&**.

* Fixed **%~d0** variables. When file modifiers are called on the **%0** 
  argument, the path used is the path of the current executed batch.

* Fixed string search functions handling of escape **^** character. Before, 
  two adjacent **^** where misinterpreted as an escape anyway.

* Fixed error with conversion of local var blocks to unicode.

## Friday 25th, May ##

* Added femto-style configuration to libmatheval. Provide a @fnp@ symbol to be 
  conformant will preprocessor macros.

* Added tests for **-lm**.

* Fixed some bad libiconv linking options.

* Fixed a lot of compilation warnings.

## Tuesday 29th, May ##

* Fixed libintl messages directories and initialisation of current locale.

* Fixed **COPY** command to be more compatible to cmd.exe. The extension is 
  only enabled when **destination** is a folder or ends with a directory 
  delimiter.

* Modifyied all commands to provide more detailled errorlevel codes. Allmost 
  every command used to return -1 on error, this is not the case anymore. 
  Commands now return an **%ERRORLEVEL%** value equal to the error code 
  associated with the message printed.

## Wednesday 30th, May ##

* Fixed if behaviour to be more compatible with **cmd.exe**. It now supports 
  the use of **&** and **|** inside the if without specifying additional 
  blocks.

* Fixed broken **COLOR** command.

* Fixed Makefile suite that erroneously linked with -lpthread when linking 
  with -lm was necessary. Also fixed makefiles trying to build libcu8 even on 
  linux

## Friday 1st, June ##

* Added a brand new editing system to the libcu8 library so that Dos9's utf-8 
  versions supports decent editing facilities like hability to insert 
  characters in the middle of the input or use history.

* Fixed a bug causing the %\* variable to contain the script name if the 
  script was launched as a separate thread inside an interpretor.

* Fixed Broken makefiles for linux.

* Fixed Broken console functions for linux.

## Wednesday 6th ##

* Fixed **%ERRORLEVEL%** variable which is now implemented as a read-only 
  variable to avoid polluting child processes environment \(especially cmd.exe 
  which behaviour gets buggy when errorlevel is defined\).

* Fixed **SET /A** command to be able to specify expression containing spaces.

* Fixed **SET** default behaviour that provided an extension breaking the 
  original command behaviour. The only behaviour used then is the old cmd 
  behaviour that truncate the input. Fixed the manual page also.

* Fixed **Dos9\_RunCommand\(\)** and added **Dos9\_Exec.c** to provide a more 
  reliable support for external command and the **START** command.

* Fixed **FIND** command to provide ErrorLevels compatible with cmd.exe, \(ie. 
  0 means "match found"\).

* Modified history behaviour of libcu8.

* Fixed broken thread function preventing correct exit values from being 
  reported to parent threads.

* Fixed **CALL** function to include search in **%PATH%** and **%pathext%** if 
  available on the system when calling file or batch. Also fixed a bug that 
  omitted the 10th parameter if more then 10 parameters were given

* Re coded **START** command.

* Enabled version 218.2.

## Friday 8th ##

* Fixed segmentation fault happening when calling a batch file with no 
  arguments and calling the **SHIFT** command from within the script 
  subsequently.

* Fixed **START** command to detect batch files extension **.bat** and 
  **.cmd** and start the appropriate **Dos9** interpretor instead of 
  **cmd.exe** by default.

* Fixed build errors under linux.

* Fixed **Dos9\_RunFile\(\)** command to be able to detect failures due to non 
  existant file or no executable files under UNIX compatible operating 
  systems.

* Introduced the **%DOS9\_START\_SCRIPT%** variable which must contain a path 
  to a script or a program to handle mymetype associations on Unix compatible 
  platform.

* Added URI support to **START** command.

* Fixed **CTRC-C** handling under UNIX compatible system.

## Monday 11th ##

* Added line editing capabilities under linux, through the use of a slightly 
  modified version of **linenoise**. Linenoise is tiny library allowing 
  console line editing. The license is shipped in COPYING.linenoise.

* Added a big change in the way blocks and **FOR** and **IF** commands are 
  handled. Now **IF** and **FOR** look ahead in the command line to see if 
  anything is to be executed using conditional operators. By default, **IF** 
  and **FOR** swallow everything to the left of the command. That is:

        for %%a in (foo bar) do echo %%a & echo loop

  is now equivalent to:

        for %%a in (foo bar) do (echo %%a & echo loop)

  This behaviour is more compatible with **cmd.exe**. To override the default 
  behaviour, please enclose the **FOR** command inside a command block as 
  follows:

        (for %%a in (foo bar) do echo %%a) & echo loop

* Incorporated some utf-8 fixes to the linenoise library.

## Wednesday 21st ##

* Added a little fix to prevent dos9 from executing line starting with a 
  column after delayed expansion.

* Do not exit when a label is encountered inside a block.

* Fixed **START** command error when trying to launch an external batch 
  script.

## Wednesday 27th ##

* Fixes to the start command.

* Removed used of **setlocale\(\)** function under windows that create a bug 
  with threads.

* Added lots of manual pages.

* Changed the way script are loaded and line executed to be more compatible 
  with cmd.exe.

* Fixes to the thread library.

## Friday, 29th ##

* Fixed bug involving pipes and wrongly inherited file descriptors created 
  after a call to **dup\(\)**.

## Monday 2nd, July ##

* Implemented **hlp**'s **help** alias as a part of **Dos9\_Auto.bat**.

* New implementation of the **dump** command.

* New makefiles for gettext files.

## Tuesday 3rd ##

* Added new target **/O:MD** for **TEA** that output markdown files. This is 
  very usefull as it helps providing more readable documentations on git 
  repositories.

* Fixed build errors for **DUMP**.

* Added **en** locale to the **po** directory and added a few fixes to make 
  the translation system easier to handle.

* Updated **README** file. It is now generated from a template used by the git 
  repository and the website so that information can be easily synced. However 
  some preprocessing is required in order to remove unnecessary broken links 
  from **README.tea**. **README.tea** is generated through a template 
  **README.tpl**.

## Wednesday 4th ##

* Added the **%~f** options to special variables.

* Updated the local variables man pages.

* Fixed a bug with **START** command. Since the output of **dos9\_start** was 
  redirected to **NUL**, and the process was not awaited, it caused problem 
  when either **mimeopen** or **xdg-open** was trying to interact with user. 
  To fix the problem, the output is no longer redirected and dos9 waits for 
  **dos9\_start** completion. This might cause little inconveniences as both 
  **xdg-open** and **mimeopen** produce some output even when run without 
  errors, but this is the only workaround found yet.

## Saturday, 7th ##

* Fixed few errors with the **DUMP** command.

* Fixed capitalised letters used inside a **#include** statement in 
  **Dos9\_UnicodeDir.c**

* Added translation for Hindi thanks to **Karanveer Chouhan \(aka kvc\)**.

* Added a tiny test suite system.

* Fixed **SET /a** bugs reported by DrNuget on the discord conversation. There 
  was essentially two bugs:

  * the **-=** operator was mistakenly handled by **Dos9** as the **/=** which 
    obviously led to unexpected behaviours.

  * Additional spaces between the variable name and the assignment operator 
    were not ignored whenever an assignment other than **=** was specified, 
    leading to errors computing the result.

* Fixed a tiny error with **femto** so that configuration target can be 
  specified in a single line.

## Sunday 15th ##

* Modified po Makefiles to stop auto-rebuild problems.

* Modified dir and variables to fix locale date formatting problems and added 
  proper setlocale.

## Monday 16th ##

* Fixed a little bug in the **Dos9\_GetNextBlockBeginEx\(\)** function.

* Added **PROMPT** command and **%PROMPT%** variable.

* Added the **PECHO** command which consists of an echo command using prompt 
  formats.

* Moved the introduction message to **Dos9\_Auto.bat**.

* Fixes to **dos9 variables** manual pages.

* Modified **COLOR** to handle new **.** extension, which refer to the current 
  default color.

* Modified the behaviour of libcu8 history.

## Tuesday 17th ##

* Fixed remaining with msgmerge that was not properly updating the timestanp 
  of generated files.

* Changed **Dos9\_Ask\(\)** input source to avoid potential conflicts with 
  buffering.

* Added bash-like auto-complete features for windows platforms, still 
  experimental though.

* Fixed errors on colors associations to code when using Unix-based operating 
  systems. Sadly this means this feature has been broken for quit a long time.

* Added bash-like auto-complete features for Unix-based operating system based 
  on linenoise. There is still some concerns that this might be broken on 
  platforms with console interraction dissabled.

* Slightly modified **Dos9\_AskConfirmation\(\)** function to be able to 
  specify some special input function in order to avoid conflicts with 
  standard buffering or raw mode.

## Saturday 21st ##

* Fixed missing inclusion of <stddef.h> in **Dos9\_Ask.h**.

* Fixed **libcu8\_read\(\)** function problem handling some characters that 
  consume more than one monospaced width. Such characters can be found using 
  **NSimSum** font on windows systems \(for example, the **§**\).

* Added **$P$G** as default **%PROMPT%** value, just in case there is no 
  **Dos9\_Auto.bat** script available.

* Added an alternate prompt for multi-line input.

* Fixed missing preprocessor directives inside **linenoise/linenoise.c** today 
  exclude **windows** targets.

## Thursday 24th ##

* Added the ESC key shortcut to clear the command under windows platforms.

* Added **dist** makefile target to make a zip of the **bin** folder when 
  called.

## Saturday 4th, August ##

* Fixed few warnings.

* Include Dos9\_DirStack.h to Dos9\_Core.h.

## Monday 6th, August ##

* Fixed Makefile bug that triggered the build of **po** sub directory even 
  when **no-nls** was used to configure the femto build suite.

* Fixed **CD** outdated manual page.

## Wednesday 8th ##

* Fixed a bug causing a segfault when using the **DIR** command.

## Friday 10th ##

* Implemented a better support to **UNC** paths. Such paths can not be used by 
  **CD** for now.

## Saturday 11th ##

* Implement a new behaviour for **XARGS** command. Each line of the input is 
  interpreted as a single parameter. Thus whenever a line containing 
  delimiters and not surrounded by quotes is encountered, quotes are 
  automatically added.

## Wednesday 15th ##

* Fixed documentation errors on **Special variable** expansions.

## Friday 17th ##

* Added the **TIMEOUT** command.

* Modified the way **Dos9** set locale so that the subject LC\_NUMERIC \(that 
  is, everything refering to numbers\) are not affected by the change.

## Sunday 19th ##

* Fixed an error introduced some commit ago that caused file search functions 
  that caused a '/' to be added before the '/' root sign when using linux.

* Fixed an error with linenoise custom autocompletion mecanism not adding a 
  final '0' character to the line, resulting in buffer overflows.

* Fixes to manual pages.

* Fixes to non-unicode windows version.

* Fixes to manual pages generation systems.

## Wednesday 22nd ##

* Fixed scripts makefiles.

* Fixed a bug with Dos9\_AskConfirmation keyboard routine.

## Sunday 26th ##

* Fixed a bug with serialisation of sub process creation. Indeed, as Dos9 is 
  multi-threaded, many different process can be creating at nearly the same 
  time, causing file inheritance issues with pipes.

* Fixed a bug with history completion.

* Fixed an error with the disk parameter **%~d** with special variables.

## Monday 1st, October ##

* Fixed a bug where the closing parenthesis was not recognised as a delimiter 
  for files names when using redirections.

## Wednesday 3rd ##

* Fixed an annoying bug of the windows version that used autocompletion when 
  prompting the user a question, resulting sometimes on unconvienient nested 
  user prompts.

* Added a mutex to serialize calls to the ECHO command between subthreads. 
  Indeed before this, several simultaneous calls to ECHO resulted in 
  interlaced messages, and garbage-like text.

* Fixed an unitialized variable bug in the RMDIR command code.

## Thursday 4th ##

* Fixed redirections not being handled when combined with pipes.

* Fixed shift command bug.

* Fixed an error with special variable expansion.

## Thursday 31st ##

* Added the MOD command and a module toolkit to create simple dynamic link 
  modules for Dos9. The object files to build modules can be found in 
  modules/lib and a very simple sample module is available in modules/sample.

## Sunday 3rd, November ##

* Fixed a bug of block parsing preventing proper handling of redirections when 
  mixed with top-level blocks.

* Slight fixes to MOD and module apis.

* Lots of changes to the console apis of libDos9, changed functions to require 
  stream as argument and got rid of the duplicated functions inside Dos9 and 
  initialisation functions

* Added an experimental batbox module.

## Sunday 11st ##

* Fixed PAUSE command misuse of Dos9\_Getch\(\).

* Fixed omitted thread locale attribute within MORE command code.

* Fixed Dos9\_GetVar\(\) and Dos9\_UnEscape\(\) functions which happenned to 
  be very slow on very large inputs.

* Modified ESTR\* lib to extend buffer exponentially rather linearly.

* Added functions to the batbox module.

## Thursday, 29th ##

* Added 'no-modules' options to build Dos9 without module support on platforms 
  that do not provide it.

* Fixed THANKS file to thank Xenoxis for his contribution to the codebase with 
  the **VER** command.

* Slightly modified the internationalization semantics used by Dos9 in order 
  to fix slight Windows issue related to some message containing '\n' that 
  were not translated to '\r\n'. The semantics have been changed, in order to 
  fix this issue, as follows \(this is further discussed in GUIDELINES\):

  * Help messages have '\n' translated to the appropriate sequences on the 
    fly, so these may still contain newlines.

  * On the other hand, both normal and error message must not contain any 
    newline. Furthermore, it up to the command to print appropriate sequences 
    using DOS9\_NL when displaying a normal message.

## Sunday 1st, December ##

* Fixed a bug preventing DOS9\_COLOR\_DEFAULT to work on unix-compatible 
  operating systems.

* Fixed omitted libdl link flag inside Dos9's makefile.

## Saturday 8th, December ##

* Improved femto by adding femto-clean and by using femto-test.out to avoid 
  using compiler-default file output \(such as a.exe or a.out\).

* Removed dump.h from git repository \(which is useless since it is 
  automatically generated with platform-specific values\).

* Fixed 

        make bin

build without prior 

    make all

.

## Thursday 13rd ##

* Changed name of **TEST\_\*\_PATH\(\)** macro families to 
  **DOS9\_TEST\_\*\_PATH\(\)** to add more consistency to the source code.

* Removed old outdated man page reffering to dropped external commands.

* Added a fix to the batbox modules to make color codes portable across all 
  supported platforms.

* Fixed man page typos.

* Added manual page for the **VER** command.

* Added manual page for the **MOD** command.

## Sunday 15th, December ##

* Fixed searching issues with hlp script and implemented **help /l**.

* Fixed a little bug that caused %PATH% search functions to loop through 
  %PATH% files even when given a relative path.

* Changed the behaviour of the **MOD** command. Modules are now search by 
  default inside **%DOS9\_PATH%/modules** \(rather that in the whole 
  **%PATH%** directories\), unless if the module file name is absolute; in 
  that case **MOD** uses the file referred to by the absolute path.

* Fixed a bug of **SET /a:f**. When expression contained spaces, the return 
  value was systematically 0.

## Monday 16th, December ##

* Improved consistency between **command /?**, now **dos9 /?** and **dump 
  /?** use stderr/fError instead of stdout as output \(which is more 
  consistent with internal commands\).

## Monday 24th ##

* Fixed set /p not providing history features under both windows and unices.

* Switched to version 218.3

## Thursday 27th ##

* Fixed missing documentation for **batbox** modules. Modified **README** and 
  **GUIDELINES**.

* Fixed missing static qualifiers in libDos9.

* Fixed recursive file search under Linux and non-unicode windows.

* Fixed a bug with **%~d** under \*nices causing double root symbol on paths.

## Monday, Junuary 14th ##

* Added **src-dist** target to **Makefile** to automatically build source code 
  tarballs ready to be distributed and/or uploaded on the website.

* Fixed a bug involving **Dos9\_RunBlock\(\)** not parsing blocks correctly.

## Thursday 17th ##

* Finally fixed **hlp.bat** to make it able to be run from any directory, 
  especially when the said directory names contains parenthesis or spaces 
  \(what is very often the case under windows\).

## Monday, May 1st, 2020 ##

* Fixed a double declaration inside the code of libinteval.

## Wednesday, May 3rd, 2020 ##

* Fixed hlp bug with Dos9 on another drive than user directory on Windows.

## Thursday, May 4th, 2020  ##

* Fixed pushd memory leak.

* Reworked directory stack :

* Fixed directory stack allocation bug that makes directory stack unusable 
  after a Dos9\_PopDir\(\) that cleared the stack.

* Makes Dos9\_CloneInstance\(\) aware of directory stack.

* Fix mod deadlock when there is a module loaded.

## Sunday, July 19th ##

* Fixed Makefile for building po files. Some builds of gmake automatically 
  remove files that are not explicitelly a target of the make file so that the 
  po files \(**\*.pot** => **\*.po** => **\*.mo**\) where identified as such 
  and deleted.

## Sunday, October 4th, 2020 ##

* Fixed %=EXITCODEASCII% endianness issue. Removed unneeded switch in 
  Dos9\_Var.c.

## Thursday, October 8th, 2020 ##

* Changed Dos9\_InitConsole to don't override cursor size on Windows. 

* Fixed some building issues on Clang.

## Friday, October 10th ##

* Fixes to typos.

* Added a test to **Makefile** to check whether **Dos9** is being build using 
  **mingw-w64**. Indeed, **mingw-w64** requires 
  **\_\_USE\_MINGW\_ANSI\_STDIO** to be defined otherwise **snprintf** is 
  replaced with windows provided **\_snprintf** which does not end strings, 
  leading to a lot of errors as Dos9 assumes ANSI.

## Thursday, October 22nd ##

* Fixes to linenoise completion function that had bug on some systems.

* Added a new build option to disable linenoise because I found it somehow 
  interfered with gdb.

* Fixed a bug that caused "/" path to be canonicalized into "", causing errors

## Saturday, October 24th ##

* Fixed a bug that would not let the user add a space or a delimiter after 
  labels specifiers.

* Fixed a couple of bugs of the **FOR** command :

  * Allow spaces to be inserted in **delims=** specifiers and provide a more 
    robust parsing function for **FOR /F** options.

  * Fixed incorrect behaviour of **eol** specifier. The **FOR /F** loop only 
    skips inputs when the first character of the line processed has been 
    specified through **eol**, this should not be a truncation.

  * Fixed incorrect behaviour of **tokens** specifiers. The **n-p** specifier 
    used to provide a concatenation of tokens from **n** up to **p** into a 
    single variable. However, in **cmd** it selects **n** up to **p** but in 
    different variables \(ie. not concatenated\). This behaviour has been 
    fixed and **Dos9** has now the same behaviour as **cmd**.

  * Added a syntax for **tokens** specifier which enables using the old 
    **n-p** behaviour. The syntax is **n.p**, it provides a variable that 
    contain all the tokens from **n** up to **p**

* Improved documentation of lookahead commands on GUIDELINES file.

## Wednesday, 11th November ##

* Fixed a bug with **femto** flag detection implementation

* Fixed a **START** bug that had omitted depreciated switches and add the 
  internal help for the start command.$

* Fixed issue with combined pipes on linux based systems.

* Fixed **MORE** command to use a proper console input file instead of 
  **fInput** when run interactively.

## Thursday, 26th November ##

* Added **tab** to default **FOR** /f loop delimiters.

## Monday, February 8th, 2021 ##

* Added the use of a win\_iconv to the **libcu8** library, to bypass using gnu 
  iconv which is way too big for portability issues.

## Monday, April 12th, 2021 ##

* Created the microgettext library to remove the **GNU gettext** library of 
  Dos9 depedencies. Dos9 has now no major dependencies aside from libdl and 
  libgcc. Statically linked it is about 400ko

* Created the experimental **LOCALE** command to provide a way to set custom 
  paths for translations

* Removed unnecessary references to Dos9\_GetExecutableName\(\)

* Fixed the if comparison behaviour for floats, numbers and such :

  * First check if the value passed are integers. If so use integer comparison

  * Then try floats. If so use float comparisons

  * Else use string lexicographical comparison

* Fixed a bug leading **^** to be considered as a variable name instead of an 
  operator

* Fixed a bug with the libcu8 prompt.

## Wednesday, April 28th, 2021 ##

* Implemented w10ansi compilation flag to implement console functions using 
  ANSI sequences instead of Windows API on Windows. Needs Windows 10 1903 and 
  Legacy Console disabled to work properly, can also work on other Windows 
  versions or with Legacy Console using ANSICON.

## Monday, May 15th, 2021 ##

* Changes to the **FOR** command documentation.

* Remove the **ENABLEFLOATS** options. The float distinction has now meaning 
  since the recent changes to the **SET /A** command. By default the command 
  uses integers, but floats are automatically triggered when a floating point 
  value is specified or when a function or a constant is used. All of this is 
  explained in details in the **SET /A** manual page.

