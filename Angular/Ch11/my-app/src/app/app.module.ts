import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';

import {AppComponent} from './app.component';
import {IntroComponent} from './intro/intro.component';
import {AppRouterModule} from './app-router.module';
import {LanguageComponent} from './language/language.component';
import {LanguageModule} from './language/language.module';


@NgModule({
  declarations: [
    AppComponent,
    IntroComponent,
    LanguageComponent
  ],
  imports: [
    BrowserModule,
    AppRouterModule,
    LanguageModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {
}
