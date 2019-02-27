import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { TwoWayBoundComponent } from './two-way-bound.component';

describe('TwoWayBoundComponent', () => {
  let component: TwoWayBoundComponent;
  let fixture: ComponentFixture<TwoWayBoundComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ TwoWayBoundComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(TwoWayBoundComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
