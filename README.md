# ScalableComputingAssignments


# Tasks done for assignment 1
1. Followed the steps mentioned to setup aws instance
2. Installed JTR and other dependencies
3. Ran the scripts 
4. Uploaded the output file to submitty


# Tasks done for assignment 2
[ All the tasks were performed local/lab machines. AWS was not used]
Approach 1
1. Use multiple instances of JTR to crack hashes
2. Tried the same thing with HashCat/RainbowCrack

Approach 2
1. Remove cracked hashes from input file.
2. Break the ~900 hash input file to smaller ~30 - ~100 sized input files and feed it to multiple instances of JTR
3. USe multiple systems available in labs to perform this task

AT this point, I was enough clues about types of hashes & passwords in my input file.
Also, till now I was not focusing much on wordlists or rules
Approach 3 (Using rules)
1. Play with the rules in config file
2. Was able to crack hashes for given rules + wordlist fairly quickly

At this point I had started writting scripts to generate wordlists. 
I was planning to use different wordlist on different systems(lab machines) to distribute the cracking task. (this would have been my 5th approach but wasn't required)
However, I was able to crack all the hashes using a wordlist(~133Mb) I found on the web.
Approach 4 (Using wordlist)
1. Divide the wordlist in smaller wordlists (~15 Mb each)
2. Used ~10 lab machines to run JTR and crack the hashes
3. Started the process on a Saturday evening; it was done when I check on Sunday morning
Observation: I had provided one machine with the original wordlist(~133 Mb); It was also able to complete the cracking process in good time


## Tasks done for assignment 3
Approach 1
1. Sort input file to segregate hashes
2. Create 6 input files with only one type of hash
3. Start cracking with the same wordlist used in assignment 2 and hope to find meaningful patterns


