import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { TypeScriptLangComponent } from './type-script-lang.component';

describe('TypeScriptLangComponent', () => {
  let component: TypeScriptLangComponent;
  let fixture: ComponentFixture<TypeScriptLangComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ TypeScriptLangComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(TypeScriptLangComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
