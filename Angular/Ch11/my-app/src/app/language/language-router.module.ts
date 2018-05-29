import {NgModule} from '@angular/core';
import {CommonModule} from '@angular/common';
import {RouterModule, Routes} from '@angular/router';
import {JavaLangComponent} from './java-lang/java-lang.component';
import {JavaScriptLangComponent} from './java-script-lang/java-script-lang.component';
import {TypeScriptLangComponent} from './type-script-lang/type-script-lang.component';

const languageRoutes: Routes = [
  {path: 'language/java', component: JavaLangComponent, outlet: 'language'},
  {path: 'language/javascript', component: JavaScriptLangComponent, outlet: 'language'},
  {path: 'language/typescript', component: TypeScriptLangComponent, outlet: 'language'}
];

@NgModule({
  imports: [
    CommonModule,
    RouterModule.forChild(languageRoutes)
  ],
  exports: [
    RouterModule
  ],
  declarations: [
    JavaLangComponent,
    JavaScriptLangComponent,
    TypeScriptLangComponent
  ]
})
export class LanguageRouterModule {
}
