//animal.ts
export class Animal {
  private _name: string;
  private _foot: number;

  constructor(name: string, foot: number) {
    this._name = name;
    this._foot = foot;
  }

  get name(): string {
    return this._name;
  }

  set name(value: string) {
    this._name = value;
  }

  get foot(): number {
    return this._foot;
  }

  set foot(value: number) {
    this._foot = value;
  }
}

