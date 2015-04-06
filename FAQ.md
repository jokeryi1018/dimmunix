# Frequently Asked Questions #

Dimmunix has received a lot of attention recently from programming experts and regular users alike. This FAQ attempts to answer some of the questions non-programmer end users might have, for whom finding answers in the [Dimmunix research paper](http://dslab.epfl.ch/pubs/dimmunix) or by reading [the code](http://code.google.com/p/dimmunix/) is likely not feasible.

**Can Dimmunix be employed by end users? Are there any plans to package it in a more end-user-friendly form?**

We are interested in recruiting developers to the Dimmunix open-source project, to help us make Dimmunix accessible to as wide an audience as possible, both in terms of packaging and documentation. There is no fundamental reason why Dimmunix could not be used by everybody who can use a computer. Unfortunately, we are researchers who produce research prototypes and write papers, and so we are not particularly skilled at developing user-friendly products – for that, we need the help of the open-source community.

**So far, Dimmunix apparently is focused on tracking and avoiding bugs that cause software to hang/freeze. Can it protect against other types of bugs too?**

Indeed, the current implementation distributed as open-source only provides immunity against so-called deadlocks, which cause hangs and freezes. However, the overall approach of failure immunity can be applied more broadly to other kinds of bugs and failures. Our hope is that other developers will join us in the open-source effort to help expand the general notion of failure immunity to other kinds of bugs.

**While keeping programs safe from hanging, does Dimmunix guarantee they will run correctly? For example, if Mathematica was about to hang and Dimmunix helped it avoid that, would 2+2 still be 4?**

Yes, computation will always be correct (to be more precise, it will always be as correct as in the original program). The Dimmunix runtime simply tweaks the scheduling of program threads from underneath the program, so as to "trick" it into running without hangs/freezes. Dimmunix modifies the scheduling of threads within the bounds of what a normal scheduler could do anyway. In some sense, it's like using loaded dice: you keep rolling them and there is nothing incorrect about the numbers that come out: if you roll a four-six, that is a perfectly valid outcome. In a similar way, theDimmunix runtime produces perfectly correct thread schedules, except they are occasionally biased toward those schedules that avoid the impending hang. In other words, if the dice is on the edge and could fall onto the "four" face as well as on the "six" face, and the "four" face would cause the program to hang, then Dimmunix tips it toward the "six" face.

**You tested Dimmunix mainly with server applications and developer tools, so presumably it's intended more as a tool for keeping servers safe. What about end-user programs, like browsers and email clients?**

We implemented deadlock immunity for both Java and C/C++ programs, so it can be used for any such program, whether small or big. We also tested it with the Limewire peer-to-peer filesharing application, which is an end-user program. The reason we first demonstrated Dimmunix for large server systems is that those are the toughest ones to deal with: they are big, have many threads, and if they freeze it's very bad (think of a bank's database server hanging vs. a user's browser). That's why we first targeted the MySQL and the SQLite databases, the JBoss and Apache ActiveMQ middleware, etc. However, that does not mean that Dimmunix cannot be used with any sort of general-purpose software.

**Dimmunix detects hangs and saves a signature of how the program got there (you refer to it as an "antibody"). But what does Dimmunix do with this information? Does it go in and "fix" the program by altering the code?**

No, the original program remains untouched; that is precisely one of Dimmunix's core advantages, because it does not need assistance from programmers or from users, it's all done automatically. The "deadlock signature" acts as a marker of what the program was doing when it hung in the past, and, when Dimmunix recognizes that the program is again heading the same way, it manipulates the interleaving of program threads from underneath the program, so as to make the program avoid retracing the hang-bound steps. This is all invisible to the program itself. You could say that Dimmunix fools a program into running hang-free despite the bugs it has within.

**If a community of programs share signatures (antibodies), how do you know that the signature you're getting is correct?**

The Dimmunix vaccination framework assumes a completely untrusted environment. Each participant employs a verification technique that allows each Dimmunix node to quickly check that a received signature is valid, before actually employing it to avoid hangs. Verifying the correctness of a signature is orders of magnitude cheaper and faster than producing the signature, so Dimmunix's tradeoff is a good one: it can accept signatures from anyone who cares to give them to us, but does not employ any of them until they've been locally verified. Moreover, the verification is done in the background, to not interfere with the program itself.

**Should users be worried about privacy when sharing these signatures? Is it ok for a signature generated inside a corporate environment to be shared outside the organization?**

There is no concern for privacy, because the deadlock signatures contain solely a fingerprint of a segment of execution. In other words, it may tell you things like "this user was browsing a webpage, then clicked on File, then on Open, and at that same time the webpage invoked the Flash plugin, and the entire browser hung", but it doesn't tell you which webpage it was, or what the content of that page was, or what else the user was doing. The signatures contain absolutely no data, neither of the user nor of the program itself. Knowing this signature will give you no information about what the user was looking at, what data he/she entered, etc.

**Could a network admin set up PCs in a company to share information, but not exchange it with machines outside the company firewall?**

Yes, that is easy to do, and the machines are most likely behind a corporate firewall already. However, we devised the cooperative vaccination framework to work for completely untrusted environments, where the members of the community do not trust each other. Thus, whether inside our outside the corporate network, the vaccination framework is equally safe.