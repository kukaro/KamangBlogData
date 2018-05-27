import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { JavaLangComponent } from './java-lang.component';

describe('JavaLangComponent', () => {
  let component: JavaLangComponent;
  let fixture: ComponentFixture<JavaLangComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ JavaLangComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(JavaLangComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
