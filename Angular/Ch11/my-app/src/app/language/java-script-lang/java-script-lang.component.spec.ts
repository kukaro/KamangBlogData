import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { JavaScriptLangComponent } from './java-script-lang.component';

describe('JavaScriptLangComponent', () => {
  let component: JavaScriptLangComponent;
  let fixture: ComponentFixture<JavaScriptLangComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ JavaScriptLangComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(JavaScriptLangComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
