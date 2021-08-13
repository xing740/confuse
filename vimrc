syntax enable "高亮
colorscheme mon2
""colorscheme evening
""set foldmethod=syntax
""set mouse=a

"在新机器配置时，要删除vim中plugged中的插件，再重新安装

call plug#begin('~/.vim/plugged')
Plug 'https://github.com/yongge666/change-colorscheme.git'
Plug 'https://github.com/vim-scripts/a.vim'
Plug 'ctrlpvim/ctrlp.vim'
Plug 'mileszs/ack.vim'
Plug 'https://github.com/pangloss/vim-javascript.git'
Plug 'https://github.com/leafgarland/typescript-vim'
Plug 'w0rp/ale'
"Plug 'https://github.com/bling/vim-airline'

""Plug 'scrooloose/nerdcommenter'
call plug#end()
set cmdheight=1

"常用的命令
" :PluginList       - 列出所有已配置的插件
"  :PlugInstall     - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
"  :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
"  :PlugClean      - 清除未使用插件,需要确认; 追加 `!`
" 自动批准移除未使用插件

"显示正在编译的文件名"
set statusline+=%f
set laststatus=2
"搜索到的字符显示高亮
set hlsearch
set relativenumber

"忽略大小写"
set ic

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

"一键保存"
:imap <C-]> <ESC><S-:>w<CR>
:map <C-]> <ESC><S-:>w<CR>

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
""set tags=/home/xing/gamecode/svr_source/tags
set tags=/data/lsfz_test_s001a/server/svr_source/tags
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
map <C-u> <S-:>AV<CR> 
"垂直"
""map 9 <S-:>AS<CR>

"ctrlp"
"按文件名进行搜索
let g:ctrlp_by_filename = 1
"不会重复打开文件，会跳到已打开的窗口"
let g:ctrlp_switch_buffer = 'et'
"忽略的目录"
set wildignore+=*/net/*
set wildignore+=*/obj/*
"x 水平 v 垂直"

set nocp

let g:ackprg = 'ag --nogroup --nocolor --column --ignore-dir={tags,game.vcxproj,obj,game.vcxproj.filters,nedmalloc,threadpool,zlib,net}'
"区分大小写
let g:ackprg = 'ag --nogroup --nocolor --column --smart-case --ignore-dir={tags,game.vcxproj,obj,game.vcxproj.filters,nedmalloc,threadpool,zlib,net}'
"全局搜索快捷键"
map <C-f> :Ack<space>


"ale"
"显示状态栏+不需要高亮行
let g:ale_sign_column_always = 1
let g:ale_set_highlights = 0
""错误和警告标志
let g:ale_sign_error = 'x'
let g:ale_sign_warning = '!'
""文件保存时，显示警告
let g:ale_lint_on_text_changed = 'never'
let g:ale_lint_on_enter = 0
let g:ale_linters_explicit = 1

let g:ale_linters = {
            \   'cpp': ['g++'],
            \  }
" C++ 配置检查参数
let g:ale_cpp_cc_options = '-std=c++14 -I/data/lsfz_test_s001a/server/svr_source/common -I/data/lsfz_test_s001a/server/svr_source/game_def -I/usr/local/include -I/usr/local/include/mongo'

nmap <silent> <C-j> <Plug>(ale_next)                                                                                                                                                    
"autojump"
""[[ -s /home/xing/.autojump/etc/profile.d/autojump.sh ]] && source /home/xing/.autojump/etc/profile.d/autojump.sh


""批量注释
""ctrl+v  选择   I    输入注释符   esc
""ctrl+v  选择   d

"比较不同:vim -d f1 f2  已打开一个:vert diffsplit f3  都打开了,分别输入diffthis   更新diffupdate"
