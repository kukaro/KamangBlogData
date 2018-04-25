import {Directive, ElementRef, HostListener, Input} from '@angular/core';

@Directive({
  selector: '[appHighlight]'
})
export class HighlightDirective {

  @Input('appHighlight')
  color: string;

  constructor(private el: ElementRef) {
    this.color = null;
  }

  @HostListener('mouseenter')
  mouseEnter() {
    this.el.nativeElement.style.backgroundColor = this.color;
  }

  @HostListener('mouseleave')
  mouseLeave(){
    this.el.nativeElement.style.backgroundColor = null;
  }
}
