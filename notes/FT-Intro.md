---
papersize: A4
title-block-style: default
title: Fourier Transform
subtitle: \indent What does it mean, why does it exist, how does it work, where is applied?
author: mariana v.
#thanks: Thanks to X, Y, and Z for helpful comments.
date: today
date-format: short
abstract: \indent  
note: \indent
output: pdf-document
fontsize: 11pt
documentclass: article
linestretch: 2
link-citations: true
linkReferences: true
bibliography: [bibliography.bib]
indent: true
---
# Introduction{-}

As part of Harmonic Analysis, Fourier Analysis is composed by four variants:

-     Fourier Series
-     Fourier Transform
-     Discrete-Time Fourier Transform
-     Discrete Fourier transform

The current study session is dedicated to Fourier Transforms, after a diagonal assessment of google results, this mathematical tool seems to be a generalized form of a decomposition process, taking an input recorded from a temporal perspective, Time - Domain, to a filtered viewpoint of its components and attributes, Frequency-Domain.
























<div style="page-break-after: always"></div>

The key differential element that distinguishes the Fourier Series from the Fourier Transform is the aspect of time. Is the input periodic as in within a range of time, or it not?

The mathematical tool applicable non-periodic signals is the Fourier transform.
For periodic signals the applicable approach is the Fourier Series. The first is derived from the latter extending the series to the non-periodic functions and avails the viewpoint in a sinusoidal formulation.

In an attempt to process what I've learned so far, here it is an outlined scenario:

- Air pressure, occurs at rate x per second
- Considering a binary system of information categorized by the states : 
    - on and off, 
    - when represented in terms of time and captured as a snapshot
    - would possibly register as illustrated as:

```bash
state
        on  |        _______
            |       |       |
            |       |       |
        off |_______|_______|___________ 
            0       1       2       3      t in seconds
```

The previous abstraction suggests that a horizontal axis in a two-dimensional space, represents time, measure in seconds, and the vertical axis represents the state [0,1]

Considering an input which alters its state once every two seconds:
    - The time period this vibrating body is 0.5 seconds
    - Being the "time period" the time of a full cycle
        - or the time it takes for the change between zero and one, given a moment.

If we imagine this oscillation between states as point continuously moving through around a circle, the center of this circle representing the *off state*, and the radius *the on* state, the speed that takes the point over a full cycle around a circle, the movement from one state to the other, appears to be correlated with the shape of a wave, but wrapped around on itself.

After a brief and modest "Eureka" moment, I started to grasp the following image:

![Alt text](https://file%2B.vscode-resource.vscode-cdn.net/c%3A/Users/valdetar/journals/Ft-An-Overview/fig/Capturar.PNG?version%3D1674893596780)

# Waves{--}

* Amplitude: maximum distance between
     the horizontal axis and the vertical position of the waveform.
     * A sine wave with an amplitude
     of 5 V, for example, has a maximum value of +5 V and a minimum value of –5 V  
* Frequency: how quickly the sinusoid completes full cycles
    * influences the maximum rate at which a sinusoidal signal can transmit information  
* Phase: the horizontal position of a waveform with
    respect to one cycle  
    * Phase shift / Phase difference: signal is shifted
           to the left or right relative to another signal or to a theoretical reference signal  

![Alt text](http://www.allaboutcircuits.com/uploads/articles/3.3_Characteristics_of_Sinusoidal_Signals3_.jpg)

An unmodified expression of the type f(x) = sin(x) or f(x) = cos(x) will produce a sinusoidal waveform, but how do we account for the fact that sinusoidal voltage and current signals have different amplitudes, frequencies, and phase shifts?
these characteristics can be incorporated as parameters into mathematical expressions built around sin() or cos().

Amplitude is denoted by the letter A, frequency by f, and phase by the Greek letter ϕ (phi). The independent variable is time, denoted by t. Everything is arranged as follows


$$
f(t)=Asin(2πft+ϕ) or f(t)=Acos(2πft+ϕ)\
$$


# Time and Circles{--}

As mentioned before, physical phenomena evolving in time, in a re-cycling fashion, have a direct representation in the Time - Domain.

Throughout history, Human civilizations have left us a lasting symbolism attached to circular shapes. Through drawing, cravings, books and foundations of mathematics. The patterns of celestial bodies in the sky, rivers flowing into oceans turn to rain and flooding rivers. Many dedicated their lives pursuing this powerful idea.

Moreover, this circular idea is part of a "group" of concepts, along with: speed, time and distance. 

![Alt text](https://d1whtlypfis84e.cloudfront.net/guides/wp-content/uploads/2019/12/12092939/download-7-1.png)

To find the speed, we need distance traveled over some known time period. 
$$Speed  =  Distance/Time$$
$$S = d/t$

To find the distance, we need to know the time and speed of the object.

$$Distance = Speed × Time$$
$$d = s × t$$

Time cam be computed in motion, to cover some distance with a known speed

$$Time =  Distance/Speed$$
$$t =  d/s$$

    Speed is measured in the unit of a meter per second  
    i.e. ms−1. As distance is measured in meter and time is
    measured in seconds.

## Dependency and variation


When 
$$α
, β
 and γ
 in αd2dt2x(t)+βddtx(t)+γx(t)=f(t)
 do not depend on the time, t, and in the absence of an external force, that is for free motion, time enters in (αd2dt2x(t)+βddtx(t)+γx(t)=f(t)$$
 only through derivatives. Then the equation of motion has the form.

αd2dt2x(t)+βddtx(t)+γx(t)=0(1.3.1)

# Motion{--}

On what ground are the Fourier tools laid upon? The answer depends, of the desired output. As an introductory and naive approach, it seemed relevant to seek technical definitions, and understand the underlaying concepts of such core ideas. Sir Isaac Newton, in Philosophiæ Naturalis Principia Mathematica, based his description of planetary motions, introducion the notion of a medium allowing this particular set of dynamic interaction. 
%In his aether model, Newton describes aether as a medium that "flows" continually downward toward the Earth's surface and is partially absorbed and partially diffused. This "circulation" of aether is what he associated the force of gravity with to help explain the action of gravity in a non-mechanical fashion.
 Kepler had a mystical belief that the circle was the Universe’s perfect shape, and that as a manifestation of Divine order, the planets’ orbits must be circular. For many years, he struggled to make Brahe’s observations of the motions of Mars match up with a circular orbit.

Eventually, however, Kepler noticed that an imaginary line drawn from a planet to the Sun swept out an equal area of space in equal times, regardless of where the planet was in its orbit. If you draw a triangle out from the Sun to a planet’s position at one point in time and its position at a fixed time later—say, 5 hours, or 2 days—the area of that triangle is always the same, anywhere in the orbit. For all these triangles to have the same area, the planet must move more quickly when it is near the Sun, but more slowly when it is farthest from the Sun.

This discovery (which became Kepler’s second law of orbital motion) led to the realization of what became Kepler’s first law: that the planets move in an ellipse (a squashed circle) with the Sun at one focus point, offset from the center.

 By unifying all motion, Newton shifted the scientific perspective to a search for large, unifying patterns in nature. Newton outlined his laws in Philosophiae Naturalis Principia Mathematica (“Mathematical Principles of Natural Philosophy,”) published in 1687.

Law I. Every body perseveres in its state of rest, or of uniform motion in a right line, unless it is compelled to change that state by forces impressed theron.

In essence, a moving object won’t change speed or direction, nor will a still object start moving, unless some outside force acts on it. The law is regularly summed up in one word: inertia.

Law II. The alteration of motion is ever proportional to the motive force impressed; and is made in the direction of the right line in which that force is impressed.

Newton’s second law is most recognizable in its mathematical form, the iconic equation: F=ma. The strength of the force (F) is defined by how much it changes the motion (acceleration, a) of an object with some mass (m).

Law III. To every action there is always opposed an equal reaction: or the mutual actions of two bodies upon each other are always equal, and directed to contrary parts.

As Newton himself described: “If you press a stone with your finger, the finger is also pressed by the stone.”



![Isaac Newton demonstrated his universal law of gravitation by showing that a comet visible during 1680 and 1681 followed the path of a parabola. [Adapted from Isaac Newton, 1687. Philosophiae Naturalis Principia Mathematica (“Mathematical Principles of Natural Philosophy.”)]](https://earthobservatory.nasa.gov/ContentFeature/OrbitsHistory/images/newton_comet_orbit.png)


Einstein and Relativity
The ideas outlined in Newton’s laws of motion and universal gravitation stood unchallenged for nearly 220 years until Albert Einstein presented his theory of special relativity in 1905. Newton’s theory depended on the assumption that mass, time, and distance are constant regardless of where you measure them.

The theory of relativity treats time, space, and mass as fluid things, defined by an observer’s frame of reference. All of us moving through the universe on the Earth are in a single frame of reference, but an astronaut in a fast-moving spaceship would be in a different reference frame.



# Simetry 

[@curie1966symmetry]

# Frequency{-}

The Frequency - Domain, 

![Alt text](https://cdn8.openculture.com/2017/04/11003129/coltrane-circle-new.jpg)



«The primary evidence should not be interchanged with the evidence of the
"axioms"; since the axioms are mostly the result already of an original
formation of meaning and they already have this formation itself always
behind them» [Husserl, The origin of Geometry, 1933].
















    - Amplitude: 
        - positive: the height of the wave from 0
        - negative: the height of the wave from bellow 0
        - peak-to-peak: change between the highest and lowest amplitude
    - Wave length: distance between two points identical in height and slope

From the data above: 

![Alt text](https://study.com/cimages/multimages/16/waveperiodformula.png)


f=ω/2π
f=v/λ
f=1T



# Waves{--}

This brought me to seek a deeper understanding about waves, as shallow as it may be, contributed for the intuitive links that will follow:
    - the sine wave, and the higher the velocity   around the circle, the higher the frequency.

there are different ways to compute the frequency of a phenomena, in the context of this paper, the frequency of teh signal can be measured according the information or data available:




# Pressure Waves{-}
# Series to transform {-}
# Circular Path {-}
# Reverse {-}
# Fast Fourier Transform{-}
# FT Visualizations C Julia {-}
# Small program WIP {-}
# Applications in Signal Processing {-}
# Others {-}

[@sadasiv1988arithmetic]

<!-- this is a comment connntaining the running code to paste into the command line:
pandoc -s -N --filter pandoc-crossref --bibliography 'bibliography.bib' --filter pandoc-citeproc FT-Intro.md -o FT.pdf
-->