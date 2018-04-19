import {Component} from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  showName = function (name: string) {
    alert(name);
  };
  showAge = (age: number) => alert(age);
}
