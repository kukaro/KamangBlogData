import {NgModule} from '@angular/core';
import {IntroComponent} from './intro/intro.component';
import {LanguageComponent} from './language/language.component';
import {RouterModule, Routes} from '@angular/router';

const appRoutes: Routes = [
  {path: 'introduce', component: IntroComponent, outlet: 'root'},
  {path: 'language', component: LanguageComponent, outlet: 'root'},
];

@NgModule({
  imports: [
    RouterModule.forRoot(
      appRoutes,
      {enableTracing: true} // 디버그시 사용
    ),
  ],
  exports: [
    RouterModule
  ],
  declarations: []
})
export class AppRouterModule {
}
