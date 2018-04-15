import {Component} from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  nameList = {'kukaro': '26', 'jiharu': '26', 'limzz': '24', 'ekekdid': '25'};
  objectKeys = Object.keys;
}
