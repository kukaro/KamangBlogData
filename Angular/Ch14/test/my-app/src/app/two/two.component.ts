// two.component.ts
import {Component, OnInit} from '@angular/core';
import {ActivatedRoute} from '@angular/router';

@Component({
  selector: 'app-two',
  templateUrl: './two.component.html',
  styleUrls: ['./two.component.css']
})
export class TwoComponent implements OnInit {

  private dataTwo: string;

  constructor(route: ActivatedRoute) {
    this.dataTwo = route.snapshot.data[0]['staticData'];
  }

  ngOnInit() {
  }

}
