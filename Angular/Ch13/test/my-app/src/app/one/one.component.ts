// one.component.ts
import {Component, OnInit} from '@angular/core';
import {ActivatedRoute} from '@angular/router';

@Component({
  selector: 'app-one',
  templateUrl: './one.component.html',
  styleUrls: ['./one.component.css']
})
export class OneComponent implements OnInit {

  private paramOne: string;

  constructor(route: ActivatedRoute) {
    this.paramOne = route.snapshot.params['pid'];
  }

  ngOnInit() {
  }

}
