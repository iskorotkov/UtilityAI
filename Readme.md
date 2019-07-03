# TODO

## Cleanup

- [ ] replace all usings of 0.0 and 1.0 with constants from UtilityAIConstants
- [ ] mark methods and classes "final" where possible
- [ ] check UPROPERTY macros with EditAnywhere/VisibleAnywhere and replace in with more strict specifiers

## Fixes and enhancements

- [ ] provide methods for direct creation of NOT, OR, AND, etc operations (do not use CreateXXXOperation methods)
- [ ] multioperations can get invalid number of arguments - fix
- [ ] array of conditions keeps collapsing when adding new conditions

## Improvements

- [x] add "cut out" value - if there is no action rated below given limit, agent does nothing
- [ ] add "DoNothing" action
- [ ] add AlwaysTrue and AlwaysFalse predicates (for testing purposes?)
- [x] add max value - any action that is rated above certain limit is executed immediately and the rest actions are ignored
- [ ] add base value for action (instead of 0.0f by default)

## Features

- [ ] add logging (with custom categories)
- [ ] IAgent should give access to AgentData object that should work like blackboard

## Propositions

## Docs

I need to write an actual doc!

## Contribution

Create a dedicated file and move this section there!
