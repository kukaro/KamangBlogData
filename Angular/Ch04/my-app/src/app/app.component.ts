import {Component} from '@angular/core';

@Component({
  selector: 'app-root',
  template: '' +
  '<h1 mine-h1>My name is {{name}}</h1>' +
  '<p>hi~!</p>' +
  '<p mine-p>This is my firsts {{title}}!</p>',
  styles: ['[mine-h1]{color: royalblue}', 'p[mine-p]{color: salmon}'],
})
export class AppComponent {
  name = 'kukaro';
  title = 'Angular';
}
