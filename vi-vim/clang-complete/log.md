#vi
##InstallVundle
Vundle 설치에 대한 포스팅 시작  
참고 url은 아래와 같다.  
https://github.com/VundleVim/Vundle.Vim#quick-start  

git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim  
위의 명령어를 입력해서 저장소에서 Vundle을 다운받는다.
vi .vimrc  
위의 명령어로 vim의 플러그인을 설정해준다.  

```
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
...
" Plugin 'git://git.wincent.com/command-t.git'
" Plugin 'file:///home/gmarik/path/to/plugin'
...
call vundle#end()
```
내가 실제로 타이핑한 코드는 아래와 같다.  
```
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
call vundle#end()
```
이제 명령모드에서 :PluginInstall을 타이핑 해보자.  
http://vlee.kr/1211  
위 url에서 번들 플러그인 단축키등을 참고함  
i : Install plugin  
c : Clean up  
s : Search  
R : Reload list  
