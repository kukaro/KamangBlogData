import requests

strUri = 'http://api.welcome.kakao.com'
strMethod = 'post'
sub = '/start'
formData = {'user_key': 'UZ23YgmDoVjOQIqml0WEqgW+GuV+k59g1Q390cYwGqmD1', 'problem_id': 0, 'number_of_elevators': 4}

startData = requests.post(strUri + sub + '/' + formData['user_key'] + '/' + str(formData['problem_id']) + '/' + str(
    formData['number_of_elevators'])).json()
is_finished = False
# cp(startData)

maxFloor = 5
debug = 0
state = None

cp = print


# def myfunc(args):
#     pass
#
#
# cp = myfunc

while True:
    # if debug == 37:
    #     break
    callData = requests.get(strUri + '/oncalls', headers={'X-Auth-Token': startData['token']}).json()
    cp(str(debug) + ' : ' + '*' * 150)
    cp('callData : ' + str(callData))
    is_finished = callData['is_end']
    if is_finished:
        break
    elevators = callData['elevators']
    calls = callData['calls']
    form = {'commands': []}
    for elevator in elevators:
        passengers = elevator['passengers']
        if elevator['status'] == 'STOPPED':
            tmparr = []
            isMove = True
            for i in range(len(calls)):
                # OPEN
                if calls[i] is not None and (
                        calls[i]['start'] == elevator['floor']):
                    form['commands'].append({'elevator_id': elevator['id'], 'command': 'OPEN'})
                    calls[i] = None
                    isMove = False
                    break
            # UP or DOWN
            isLastCase = True
            if isMove:
                # OPEN
                for passenger in passengers:
                    if passenger['end'] == elevator['floor']:
                        form['commands'].append({'elevator_id': elevator['id'], 'command': 'OPEN'})
                        isLastCase = False
                        break
                if isLastCase:
                    if elevator['floor'] != maxFloor and (elevator['floor'] == 1 or state == 'UP'):
                        form['commands'].append({'elevator_id': elevator['id'], 'command': 'UP'})
                        state = 'UP'
                    elif elevator['floor'] != 1 and elevator['floor'] == maxFloor or state == 'DOWN':
                        form['commands'].append({'elevator_id': elevator['id'], 'command': 'DOWN'})
                        state = 'DOWN'

            pass
        elif elevator['status'] == 'UPWARD':
            # 내리는거
            isExitCase = False
            isLastCase = True
            call_ids = []
            for passenger in passengers:
                if passenger['end'] == elevator['floor']:
                    call_ids.append(passenger['id'])
                    isExitCase = True
                    break
            if isExitCase:
                form['commands'].append({'elevator_id': elevator['id'], 'command': 'STOP'})
                isLastCase = False
            else:
                for i in range(len(calls)):
                    if calls[i] is not None and calls[i]['start'] == elevator['floor']:
                        form['commands'].append({'elevator_id': elevator['id'], 'command': 'STOP'})
                        isLastCase = False
                        calls[i] = None
                        break
            if isLastCase:
                form['commands'].append({'elevator_id': elevator['id'], 'command': 'UP'})
            pass
        elif elevator['status'] == 'DOWNWARD':
            # 내리는거
            isExitCase = False
            call_ids = []
            isLastCase = True
            for passenger in passengers:
                if passenger['end'] == elevator['floor']:
                    call_ids.append(passenger['id'])
                    isExitCase = True
                    break
            if isExitCase:
                form['commands'].append({'elevator_id': elevator['id'], 'command': 'STOP'})
                isLastCase = False
            else:
                for i in range(len(calls)):
                    if calls[i] is not None and calls[i]['start'] == elevator['floor']:
                        form['commands'].append({'elevator_id': elevator['id'], 'command': 'STOP'})
                        isLastCase = False
                        calls[i] = None
                        break
            if isLastCase:
                form['commands'].append({'elevator_id': elevator['id'], 'command': 'DOWN'})
            pass
        elif elevator['status'] == 'OPENED':
            isClose = True
            # EXIT
            exitarr = []
            for passenger in passengers:
                if passenger['end'] == elevator['floor']:
                    exitarr.append(passenger['id'])
            if len(exitarr) != 0:
                form['commands'].append({'elevator_id': elevator['id'], 'command': 'EXIT', 'call_ids': exitarr})
                continue
            for i in range(len(calls)):
                # ENTER
                print(calls)
                if calls[i] is not None and calls[i]['start'] == elevator['floor']:
                    form['commands'].append(
                        {'elevator_id': elevator['id'], 'command': 'ENTER', 'call_ids': [calls[i]['id']]})
                    calls[i] = None
                    isClose = False
                elif calls[i] is not None and calls[i]['start'] != elevator['floor']:
                    continue
                # CLOSE
            if isClose:
                form['commands'].append({'elevator_id': elevator['id'], 'command': 'CLOSE'})

            pass
    cp('form : ' + str(form))
    actionData = requests.post(strUri + '/action', json=form,
                               headers={'X-Auth-Token': startData['token'], 'Content-Type': 'application/json'}).json()
    cp('actionData : ' + str(actionData))
    debug += 1
# if is_finished:
#     break
