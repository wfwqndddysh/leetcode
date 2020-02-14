#!/usr/bin/env bash

# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | awk '{ print $2, $1 }'
cat words.txt | xargs -n1 | sort | uniq -c | sort -nr | awk '{print $2 " " $1}'
