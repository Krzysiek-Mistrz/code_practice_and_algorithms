abstract class Character
{
    protected int _damage;
    protected bool _vulnerable;
    protected string _type;

    protected Character(string characterType)
    {
        _type = characterType;
    }

    public abstract int DamagePoints(Character target);

    public virtual bool Vulnerable() => _vulnerable;

    public override string ToString() => $"Character is a {_type}";
}

class Warrior : Character
{
    public Warrior() : base("Warrior")
    {
        _damage = 6;
        _vulnerable = false;
    }

    public override int DamagePoints(Character target)
    {
        return target.Vulnerable() ? 10 : 6;
    }
}

class Wizard : Character
{
    private bool _spellPrepared = false;

    public Wizard() : base("Wizard")
    {
        _damage = 3;
        _vulnerable = true;
    }

    public override int DamagePoints(Character target) => _damage;

    public void PrepareSpell()
    {
        _spellPrepared = true;
        _vulnerable = false;
        _damage = 12;
    }

    public override bool Vulnerable() => _vulnerable;
}
