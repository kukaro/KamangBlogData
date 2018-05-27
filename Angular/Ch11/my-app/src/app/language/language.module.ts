import {NgModule} from '@angular/core';
import {CommonModule} from '@angular/common';
import {RouterModule, Routes} from '@angular/router';
import {LanguageRouterModule} from './language-router.module';


@NgModule({
  imports: [
    CommonModule,
    LanguageRouterModule
  ],
  declarations: [
  ]
})
export class LanguageModule {
}
