// app.module.ts
import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';

import {AppComponent} from './app.component';
import {OneComponent} from './one/one.component';
import {TwoComponent} from './two/two.component';
import {routing} from './app.routing';
import { JavaComponent } from './java/java.component';
import { PythonComponent } from './python/python.component';


@NgModule({
  declarations: [
    AppComponent,
    OneComponent,
    TwoComponent,
    JavaComponent,
    PythonComponent
  ],
  imports: [
    BrowserModule,
    routing
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {
}
