import {Component} from '@angular/core';
import {Person} from './Person';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  kukaro = new Person('kukaro', 26);
  obj = {
    'cadSocios': true
  };
  obj2 = {
    'name': ['name1', 'name2'],
    part: ['part1', 'part2']
  };

  merged = Object.assign(this.obj, this.obj2);
}
