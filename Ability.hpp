#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Ability {
public:
    explicit Ability(const std::string& name = "", int powerLevel = 0);

    Ability(const std::shared_ptr<Ability>& other)
        : name(other->name), powerLevel(other->powerLevel) {}

    virtual ~Ability() = default;

    virtual void display() const;

    [[nodiscard]] virtual std::string getName() const;

    [[nodiscard]] virtual int getPowerLevel() const;

    virtual void addAbility(std::shared_ptr<Ability> ability);

    [[nodiscard]] static std::shared_ptr<Ability> createAbilityFromInput();

protected:
    std::string name;
    int powerLevel;
};

class CompositeAbility : public Ability {
public:
    explicit CompositeAbility(const std::string& name);

    void addAbility(std::shared_ptr<Ability> ability) override;

    void display() const override;

private:
    std::vector<std::shared_ptr<Ability>> abilities;
};

#endif // ABILITY_HPP
