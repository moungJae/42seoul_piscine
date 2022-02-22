cat /etc/passwd | grep -v "#" | cut -d ':' -f 1 | awk 'NR % 2 == 0' | rev | sort -r | awk -v s=$FT_LINE1 -v e=$FT_LINE2 'NR >= s && NR <= e' | xargs | sed -e 's/ /, /g' | sed 's/$/./g' | tr -d '\n'
