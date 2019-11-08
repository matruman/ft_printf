array=($(grep -rh "typedef" --exclude typedef.sh . | tr -d '[:blank:]' | sed "s/typedefstructs_/t_/g" | grep -v Binaryfile))
out=("hi def link cTypeCustom MyType\nhi MyType ctermfg=DarkCyan guifg=DarkCyan\n")
tmp1="syn match MyType /[a-zA-Z]\@<!"
tmp2="[a-zA-Z]\@!/\n"
for i in ${array[@]}; do
	out="$out$tmp1$i$tmp2"
done
printf "$out" > ~/.vim/syntax/c.vim
