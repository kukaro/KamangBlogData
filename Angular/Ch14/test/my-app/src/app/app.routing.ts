// app.routing.ts
import {Routes, RouterModule} from '@angular/router';
import {OneComponent} from './one/one.component';
import {TwoComponent} from './two/two.component';
import {JavaComponent} from './java/java.component';
import {PythonComponent} from './python/python.component';

const routes: Routes = [
    {path: 'one/:pid', component: OneComponent},
    {
      path: 'two', component: TwoComponent, data: [{staticData: 'kukaro'}],
      children: [
        {path: 'java', component: JavaComponent},
        {path: 'python', component: PythonComponent}
      ]
    }
  ]
;
export const routing = RouterModule.forRoot(routes);
