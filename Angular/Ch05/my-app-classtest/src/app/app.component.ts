import {Component} from '@angular/core';
import {Animal} from './animal';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  animalList = [new Animal('elephant', 4),
    new Animal('kukaro', 2,
    )];
}
