# Fourier TraNsform, 
## exploring fundamentals 
##### What does it mean, why does it exist, how does it work, where is applied?

Context

    The following pages are simple, organized notes, logged while studying.
    
    ** Due to the time constraints, several revisions and editing should follow, at the present moment is in "as is" stage.

Motivation

The topic is explored in the context of a weeks studying, alike an essay on a subject. 
with prior knowledge, solely a vague notion in a graphical context. 
The reason why I chose this subject from the three proposed:
comes from personal desire to learn, in order to one day, possibly ingress in a formal academic degree, and dedicate my life to research. Moreover, following the logical premise "generalized before specialize", the Fourier Transform, Series and Analysis, appear to be closely related with the "left out" topics. I hope by the end of this week find, in this newly acquired knowledge, a common thread between them. 

The given parameters of the task at hand were composed by three aspects:

        [1.] study the basics, and present the concept in a week. 
        [2.] what dos it mean?
        [3.] why does it exist?
        [4.] etc...

to close the circle of elementary yet fundamental questions, I structured:
    [1.] On what ground are the Fourier tools laid upon? 
    [2.] Is the Fourier transform part of a group or specific field?
    [3.] What is it's chronological pin?  
    [4.] What is it, and what does it mean? ?  
    [5.] How is it done?  
    [6.] Is there a cross-field application?  
    [7.] Can I implement, test or prove it?  
 
<!-- finish section later -->
# Introduction

## MOTION AND Nature

The individual human experience is not cyclical, we're part of a group of phenomena which happens in a linear (one direction) trajectory towrds decay and eventual death. Death, like the exposion of a bom is a non-reversible event. 

Any physical phenomena evolving in time, that presents an oscilatory behaviour, circular motion, a periodicity, can be translated in a time domain.

Throughout history, Human civilizations have left us a lasting symbolism attached to circular shapes. Through drawing, cravings, books and foundations of mathematics. The patterns of celestial bodies in the sky, rivers flowing into oceans turn to rain and flooding rivers. Many dedicated their lives to uncover the mysteries of this powerful idea.

On what ground are the Fourier tools laid upon? The answer depends, of the desired output. As an introductory and naive approach, it seemed relevant to seek technical definitions, and understand the underlaying concepts of such core ideas. Sir Isaac Newton, in Philosophiæ Naturalis Principia Mathematica, based his description of planetary motions, introducion the notion of a medium allowing this particular set of dynamic interaction. 
%In his aether model, Newton describes aether as a medium that "flows" continually downward toward the Earth's surface and is partially absorbed and partially diffused. This "circulation" of aether is what he associated the force of gravity with to help explain the action of gravity in a non-mechanical fashion.

The brilliance on which today's knowledge thrives, gave us the following idea on the continuos motion of Nature:

Moreover, any sustainable dynamic system can be described has having a core cyclic pricipal, and most of those observable or inferred dynamics comprehend the fundamental elements of the universe we know.

## Circles and Cycles

The relationship between motion and sound has extensively been explored, in "Musica Universalis" (music of the spheres) explores the theory originated in Antient Greece, developed by 16th-century astronomer Johannes Kepler. Kepler did not believe this "music" to be audible, but felt that it could nevertheless be heard by the soul. The idea continued to appeal to scholars until the end of the Renaissance, influencing many schools of thought, including humanism.

<!-- ancien egypt -->
It represents the notions of totality, wholeness, original perfection, the Self, the infinite, eternity, timelessness, all cyclic movement, God ('God is a circle whose centre is everywhere and whose circumference is nowhere' (Hermes Trismegistus)).

Roblee, Mark. “Performing Circles in Ancient Egypt from Mehen to Ouroboros.” Preternature: Critical and Historical Studies on the Preternatural 7, no. 2 (2018): 133–53. <https://doi.org/10.5325/preternature.7.2.0133>.

<!-- Rotation, air and sound -->
Cycle is an ambiguous term for the unit of frequency or hertz, since 1960 when the International system of Units replaced one for the other. Nonetheless, there seems to be an intimate correlation between the time period of a cycle, and a circle. 

The frequency domian, in analysing signals, it's seems to be as relevant, in Nature ans teh Time domain, humans have found that the domain of frquencies as as usefull to descrive phenome.

## Signals
 
sinusoldal signal receptors are commonly found in various forms in nature, thr inner ear of mammals, called cochlea, detecs air pressure sunusoids and frquencies between 20 and 20 khz.
The HUman retina also is sensitive to electromagnetic sinusois in a 430THz - 790THz range.  

the hability do detect sinusoidal  signals is intrinsicly related with performin a Fourier transoform, after all, science is the art od observation, deductiion and induction.

Signals aren't often pure as a sinusoid, and normaly are composed by diferent frquenc ressonations. The human ear, the cochlea, can receive at the "same time" varying inputs, and for example the brain, is somehow instuitivle able to decompose input into differen elements within the range of available perception.

Many have wondered if it would be possible to capture these signals and find it's elements, but in a time domain, pressure waves contain artifacts, and if register and then plotted, the shape it draws is rendered complex and even chaotic, like an array of montains in the horizon.

Decomposition of any signal into sinusoidal elements, can intuitivle be deduced as some sort of filtering processing. 
Therefore, signal processing must include a method to implemet teh right filters for the elements relevan for teh analysi at hand. 

![](https://file%2B.vscode-resource.vscode-cdn.net/c%3A/Users/valdetar/journals/Ft-An-Overview/fig/F_12_2.gif?version%3D1674811571568)

The importance of the right filter for each case can be illustrate by takin a milkshake, made by blending banana and other fruits, to detect teh fruit banana, this diseign filter for such has to be included in the method, other wise dillution of this element can "mask" the rest of the elelemnts. 

Stil on thi milkshake idea, a extremely imporat concept,  the time-invarience, represents a core configurationof signal procesing. After decomposing a milksahe into it's recipe, all its components can then be again blended togheter no matter the order in which the elementes are inserted. 

From an Synthetizing prepective, blending ingredients into the smoothie represents tgoing from the frequency domain to the time domain, and from an alanytical stand point, finding the elements of the recipe is mpving from the time domain to a frquency domain.

## Waves
If oscilatory behavior can be parametised, what then are the caratcteristic or information they may convey?

Waves and wake-like patterns display:

     variance
     periodicity
     range
     finite or continuous nature
     speed


Focusing on pressure waves, a signal a pulse, act as a disturbance moving through air. 
This disturbance transports energy, as particles are traveling subjects.

## What are Fourier Transforms?

As part of Harmonic Analysis, Fourier Analysis is composed by four variants:

     Fourier Series
     Fourier Transform
     Discrete-Time Fourier Transform
     Discrete Fourier transform


After reading, I would that is a generalized for of a decomposition process of an input recorded from a temporal perspective, into the input's components and attributes.

The key differential element that dustunguishes teh Fourier Series from the Fourier Transform is the aspect of time. Is the input periodic as in within a range of time, or it not?

The mathematical tool applicable non-periodic signals is the Fourier Transfrom.
For periodic signals the applicable approach is the Fourier Series. The first  is derived from the latter  extending the series to the non-periodic functions and avails the viewpoint in terms of simple sinusoids.

In an attempt to process what I've learnt so far, I outlined teh following scenario:
Air pressure, occurs at rate x per second, 

Considering a binary system of information categorized by the states : on and off, when represented in terms of time and captured as a snapshot, would possibly register as illustrated on the figure [n_of_figure](www.ola.com)

The previous abstraction suggests that along an horizontal axis in a two-dimensional space, representing time Measure in seconds, and a vertical axis representing the state [0,1]

Considering an input which alters it's state once every two seconds, 

```bash
state
        on  |        _______
            |       |       |
            |       |       |
        off |_______|_______|___________ 
            0       1       2       3      t in seconds
```

In this its's also valid to describe, ie: the time period of a vibrating body as 0.5 seconds,
being the "time period", the time of a full cycle, or the time it takes for the change between zero and one, given a moment.

In a two dimensional circular motion, a point can preform a cycle around a circle.
The center of a circle is the off state, and it's radius the on state. The speed that takes a for a full cycle around a circle, the alteration from one state to the other, is a beautiful idea to think about frequency. 

This brings us to the sine wave, and the higher the velocity around the circle, the higher the frequency.

there are different ways to compute the frequency of a phenomena, in the context of this paper, the frequency of teh signal can be measured according the information or data available:

    f = 1 / T
    F = V / lambda
    f = angular frw / 2 pi


![Relationship FIG](https://file%2B.vscoDe-resource.vscode-cdn.net/c%3A/Users/valdetar/journals/Ft-An-Overview/fig/Capturar.PNG?version%3D1674811502662)

## Notation

Unlike many mathematical field of science, Fourier Transform theory does not have a well
defined set of standard notations. The notation maintained throughout will be:
x, y → Real Space co-ordinates
u, v → Frequency Space co-ordinates
and lower case functions (eg f(x)), being a real space function and upper case functions (eg
F(u)), being the corresponding Fourier transform, thus:
F(u) = F { f(x)}
f(x) = F
−1
{F(u)}
where F {} is the Fourier Transform operator.
The character ı will be used to denote √
−1, it should be noted that this character differs from
the conventional i (or j). This slightly odd convention and is to avoid confusion when the
digital version of the Fourier Transform is discussed in some courses since then i and j will be
used as summation variables.

 f(x)=lima→∞fa(x),where fa(x+a)=fa(x)

![Summary](https://file%2B.vscode-resource.vscode-cdn.net/c%3A/Users/valdetar/journals/Ft-An-Overview/fig/Notation-summary-for-symbols-FT-indicates-Fourier-transform.png?version%3D1674811636942)

![](https://file%2B.vscode-resource.vscode-cdn.net/c%3A/Users/valdetar/journals/Ft-An-Overview/fig/table2.jpg?version%3D1674811675138)


## REFS

[label](refs/531B6A9EE56C8BCC879B6BA9150049.pdfC:/Users/valdetar/journals/Ft-An-Overview/refs/Connecting_Cycles_for_Concentric_Circles.pdfC:/Users/valdetar/journals/Ft-An-Overview/refs/Mobius-Bernoulli-JAT.pdfC:/Users/valdetar/journals/Ft-An-Overview/refs/ScienceDirect_articles_25Jan2023_19-56-35.149.zip)
[label](refs/Connecting_Cycles_for_Concentric_Circles.pdf)






####  (More on) MOTION AND Nature

The individual human experience is not cyclical, we're part of a group of phenomena which happens in a linear (one direction) trajectory towrds decay and eventual death. Death, like the exposion of a bom is a non-reversible event. 

Any physical phenomena evolving in time, that presents an oscilatory behaviour, circular motion, a periodicity, can be translated in a time domain.

Throughout history, Human civilizations have left us a lasting symbolism attached to circular shapes. Through drawing, cravings, books and foundations of mathematics. The patterns of celestial bodies in the sky, rivers flowing into oceans turn to rain and flooding rivers. Many dedicated their lives to uncover the mysteries of this powerful idea.


On what ground are the Fourier tools laid upon? The answer depends, of the desired output. As an introductory and naive approach, it seemed relevant to seek technical definitions, and understand the underlaying concepts of such core ideas. Sir Isaac Newton, in Philosophiæ Naturalis Principia Mathematica, based his description of planetary motions, introducion the notion of a medium allowing this particular set of dynamic interaction. 
%In his aether model, Newton describes aether as a medium that "flows" continually downward toward the Earth's surface and is partially absorbed and partially diffused. This "circulation" of aether is what he associated the force of gravity with to help explain the action of gravity in a non-mechanical fashion.

The brilliance on which today's knowledge thrives, gave us the following idea on the continuos motion of Nature:

Moreover, any sustainable dynamic system can be described has having a core cyclic pricipal, and most of those observable or inferred dynamics comprehend the fundamental elements of the universe we know.

#### (more on) CIRCLES aNd Cycles
The relationship between motion and sound has extensively been explored, in "Musica Universalis" (music of the spheres) explores the theory originated in Antient Greece, developed by 16th-century astronomer Johannes Kepler. Kepler did not believe this "music" to be audible, but felt that it could nevertheless be heard by the soul. The idea continued to appeal to scholars until the end of the Renaissance, influencing many schools of thought, including humanism.

<!-- ancien egypt -->
It represents the notions of totality, wholeness, original perfection, the Self, the infinite, eternity, timelessness, all cyclic movement, God ('God is a circle whose centre is everywhere and whose circumference is nowhere' (Hermes Trismegistus)).

Roblee, Mark. “Performing Circles in Ancient Egypt from Mehen to Ouroboros.” Preternature: Critical and Historical Studies on the Preternatural 7, no. 2 (2018): 133–53. <https://doi.org/10.5325/preternature.7.2.0133>.

Rotation, air and sound
Cycle is an ambiguous term for the unit of frequency or hertz, since 1960 when the International system of Units replaced one for the other. Nonetheless, there seems to be an intimate correlation between the time period of a cycle, and a circle. 

The frequency domian, in analysing signals, it's seems to be as relevant, in Nature ans teh Time domain, humans have found that the domain of frquencies as as usefull to descrive phenome.

Signals
 
sinusoldal signal receptors are commonly found in various forms in nature, thr inner ear of mammals, called cochlea, detecs air pressure sunusoids and frquencies between 20 and 20 khz.
The HUman retina also is sensitive to electromagnetic sinusois in a 430THz - 790THz range.  

the hability do detect sinusoidal  signals is intrinsicly related with performin a Fourier transoform, after all, science is the art od observation, deductiion and induction.

Signals aren't often pure as a sinusoid, and normaly are composed by diferent frquenc ressonations. The human ear, the cochlea, can receive at the "same time" varying inputs, and for example the brain, is somehow instuitivle able to decompose input into differen elements within the range of available perception.

Many have wondered if it would be possible to capture these signals and find it's elements, but in a time domain, pressure waves contain artifacts, and if register and then plotted, the shape it draws is rendered complex and even chaotic, like an array of montains in the horizon.

Decomposition of any signal into sinusoidal elements, can intuitivle be deduced as some sort of filtering processing. 
Therefore, signal processing must include a method to implemet teh right filters for the elements relevan for teh analysi at hand. 

The importance of the right filter for each case can be illustrate by takin a milkshake, made by blending banana and other fruits, to detect teh fruit banana, this diseign filter for such has to be included in the method, other wise dillution of this element can "mask" the rest of the elelemnts. 

Stil on thi milkshake idea, a extremely imporat concept,  the time-invarience, represents a core configurationof signal procesing. After decomposing a milksahe into it's recipe, all its components can then be again blended togheter no matter the order in which the elementes are inserted. 

From an Synthetizing prepective, blending ingredients into the smoothie represents tgoing from the frequency domain to the time domain, and from an alanytical stand point, finding the elements of the recipe is mpving from the time domain to a frquency domain.

Waves
If oscilatory behavior can be parametised, what then are the caratcteristic or information they may convey?

Waves and wake-like patterns display:

     variance
     periodicity
     range
     finite or continuous nature
     speed


Focusing on pressure waves, a signal a pulse, act as a disturbance moving through air. 
This disturbance transports energy, as particles are traveling subjects.





\end{document}
