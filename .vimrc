syntax enable "高亮
colorscheme mon2
""colorscheme evening
"set foldmethod=syntax
set mouse=a

call plug#begin('~/.vim/plugged')
Plug 'https://github.com/yongge666/change-colorscheme.git'
Plug 'https://github.com/vim-scripts/a.vim'
Plug 'ctrlpvim/ctrlp.vim'
""Plug 'scrooloose/nerdcommenter'
call plug#end()
set cmdheight=1

"常用的命令
" :PluginList       - 列出所有已配置的插件
"  :PlugInstall     - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
"  :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
"  :PlugClean      - 清除未使用插件,需要确认; 追加 `!`
" 自动批准移除未使用插件

map <F5> <S-:>tnext<CR>
map <F6> <S-:>%s/\r\+$//e<CR>
map <F7> <S-:>cn<CR>

noremap H h
"noremap J j
noremap K k
noremap L l
"noremap I i

"set complete=.,w
"set complete=.,w
set nu  "行号"
set ts=4 
set autoindent
set shiftwidth=4
set nocompatible
set expandtab

"自动补全

:inoremap ( ()<ESC>i

:inoremap ) <c-r>=ClosePair(')')<CR>

":inoremap { {}<esc>i
:inoremap { {<CR>}<ESC>O

:inoremap } <c-r>=ClosePair('}')<CR>

:inoremap [ []<ESC>i

:inoremap ] <c-r>=ClosePair(']')<CR>

:inoremap " ""<ESC>i

:inoremap ' ''<ESC>i

function! ClosePair(char)

    if getline('.')[col('.') - 1] == a:char

        return "\<Right>"

    else

        return a:char

    endif

endfunction


"ctags
map <C-d> g]
map <C-j> <C-t>
set tags=/home/xing/gamecode/svr_source/tags
"关声音
set vb t_vb=

map <F8> :NextColorScheme<CR>
imap <F8> <ESC> :NextColorScheme<CR>
map <F9> :PreviousColorScheme<CR>
imap <F9> <ESC> :PreviousColorScheme<CR>
map <F7> :colorscheme<CR>

"a.vim"
map <C-y> <S-:>A<CR>
"水平"
"map 8 <S-:>AV<CR> 
"垂直"
"map 9 <S-:>AS<CR>

"ctrlp"
"按文件名进行搜索
let g:ctrlp_by_filename = 1
"不会重复打开文件，会跳到已打开的窗口"
let g:ctrlp_switch_buffer = 'et'
"忽略的目录"
set wildignore+=*/net/*
"x 水平 v 垂直"
set nocp
