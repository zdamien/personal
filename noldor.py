#Monte Carlo simulation, estimating original number of Noldor in Valinor from Turgon's troop size.

from random import uniform

troops = 10_000
BIN = 1112
bins = [0 for i in range(BIN)]
cum = [0 for i in range(BIN)]
N = 1000_000
for i in range(N):
    troops_fighting = uniform(1/3, 1)
    #how much of Gondolon's army is the 10,000?
    adult_males_as_troops = uniform(.05, 1)
    #how many adult males are troops?
    people_as_adult_males = uniform(.5, 1)
    #how many elves are adult males?
    people_as_noldor = uniform(0.2, .4)
    #how many Gondolin are Noldor (less than half)
    turgon_as_fingolfin = 1/3
    #We know he took 1/3 of the Noldor of Fingolfin...
    fing_as_nonfea = uniform(.6, 1)
    #...but not whether that's still all of the Noldor who followed Fingolfin instead of Feanor, or if Finrod is counted separately now.
    nonfea = uniform(.6, .9)
    #More followed Fingolfin than Feanor, still true in Beleriand after Finarfin peeled off and others were lost on the Grinding Ice.
    survivors = uniform(.5, .95)
    #"the greater part" of the Nolodr survived Uinen's wrath, and I figure not *too* many were lost on the Ice.
    setout = .9
    #"a tithe" stayed home in Tirion.

    noldor = troops / troops_fighting / adult_males_as_troops / people_as_adult_males / people_as_noldor / turgon_as_fingolfin / fing_as_nonfea / nonfea / survivors / setout

    #MIN:
    #>>> 10000/.4/(1/3)/.9/.95/.9
    #97465.88693957114
    #MAX:
    #>>> 10000/(1/3)/.05/.5/.2/(1/3)/.6/.6/.5/.9
    #111_111_111.1111111

    bin = int( noldor / 100_000 )
    #print(bin)
    bins[bin] += 1

for i in range(BIN):
    cum[i] = bins[i] + (0 if i==0 else cum[i-1])
    if (bins[i]): print('{:12,d}'.format(i*100_000), bins[i]/N, cum[i]/N)
