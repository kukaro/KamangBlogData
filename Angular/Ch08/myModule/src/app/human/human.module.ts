import {NgModule} from '@angular/core';
import {CommonModule} from '@angular/common';
import {ManComponent} from './man/man.component';
import {WomanComponent} from './woman/woman.component';

@NgModule({
  imports: [
    CommonModule
  ],
  exports: [
    ManComponent,
    WomanComponent
  ],
  declarations: [ManComponent, WomanComponent]
})
export class HumanModule {
}
