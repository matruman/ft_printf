array=($(grep -rh "typedef" --exclude typedef.sh . | tr -d '[:blank:]' | sed "s/typedefstructs_/t_/g"))
out=("hi def link cTypeCustom MyType
hi MyType ctermfg=DarkCyan guifg=DarkCyan
")
tmp1="syn match MyType /[a-zA-Z]\@<!"
tmp2="[a-zA-Z]\@!/
"
for i in ${array[@]}; do
	out="$out$tmp1$i$tmp2"
done
echo "$out" > ~/.vim/syntax/c.vim
