#!/bin/bash
cat /etc/passwd | sed '/#/d' | awk 'NR%2==0' |  awk -F ':' '{print $1}' | rev | sort -r | awk $FT_LINE1'<=NR && NR<='$FT_LINE2 | tr '\n' ',' | sed 's/,/, /g' | sed 's/..$/./' | tr -d '\n' 
