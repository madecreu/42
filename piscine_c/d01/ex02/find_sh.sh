find . -name '*.sh' | rev | cut -d "/" -f 1 | rev | grep sh | cut -d "." -f 1
