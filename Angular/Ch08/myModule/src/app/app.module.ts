import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';

import {AppComponent} from './app.component';
import {TestComponent} from './test/test.component';
import {HumanModule} from './human/human.module';

@NgModule({
  declarations: [
    AppComponent,
    TestComponent,
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
