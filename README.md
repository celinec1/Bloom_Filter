# Bloom Filter for Phishing URL Detection

This project implements a Bloom filter to detect active phishing URLs. The phishing URLs are obtained from two sets of URLs contained in the phishing-links-ACTIVE.txt and phishing-links-INACTIVE.txt files. Each line in these two files is a URL. The files phishing-links-ACTIVE.txt and phishing-links-INACTIVE.txt contain two sets of phishing URLs obtained from https://github.com/mitchellkrogza/Phishing.Database

Bloom Filter Design

We will design a Bloom filter that contains the set of ACTIVE phishing links, and the false positive rate for classifying an INACTIVE phishing link as ACTIVE is minimized. The size of the Bloom filter is set to 330, and it should have a false positive rate strictly less than 30%.
