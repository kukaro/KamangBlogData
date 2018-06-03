// app.routing.ts
import {Routes, RouterModule} from '@angular/router';
import {OneComponent} from './one/one.component';
import {TwoComponent} from './two/two.component';

const routes: Routes = [
    {path: 'one/:pid', component: OneComponent},
    {path: 'two', component: TwoComponent, data: [{staticData: 'kukaro'}]}
  ]
;
export const routing = RouterModule.forRoot(routes);
