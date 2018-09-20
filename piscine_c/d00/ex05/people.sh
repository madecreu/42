ldapsearch -Q uid="z*" cn | grep "cn:" | cut -d ":" -f 2 | cut -c2- | sort -fr
