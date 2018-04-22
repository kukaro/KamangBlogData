import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';

import {AppComponent} from './app.component';
import {HumanModule} from './human/human.module';
import {ManComponent} from './human/man/man.component';
import {WomanComponent} from './human/woman/woman.component';
import { TestComponent } from './test/test.component';


@NgModule({
  declarations: [
    AppComponent,
    // ManComponent,
    // WomanComponent,
    TestComponent
  ],
  imports: [
    BrowserModule,
    HumanModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {
}
