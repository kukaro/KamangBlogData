import {Component} from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  nameList = ['kukaro', 'jiharu', 'limzz', 'ekekdid'];

  constructor() {
    for (let name of this.nameList) {
      console.log(name);
    }
  }
}
