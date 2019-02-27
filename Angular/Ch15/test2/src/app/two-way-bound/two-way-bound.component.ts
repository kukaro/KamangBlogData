// two-way-bound.component.ts
import {Component, OnInit} from '@angular/core';

@Component({
  selector: 'app-two-way-bound',
  templateUrl: './two-way-bound.component.html',
  styleUrls: ['./two-way-bound.component.css']
})
export class TwoWayBoundComponent implements OnInit {
  mydata: string;

  constructor() {
  }

  ngOnInit() {
    this.mydata = 'hi';
  }

  onValueChange($event) {
    this.mydata = $event.target.value;
  }
}
