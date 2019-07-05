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

- [ ] add AlwaysTrue and AlwaysFalse predicates (for testing purposes?)

## Features

- [ ] add logging (with custom categories)
- [x] IAgent should give access to AgentData object that should work like blackboard
- [ ] add description to actions/predicates
- [x] add preparation and cleanup actions to brain asset
- [ ] add multiple passes to Utility Ai component (each pass is a single brain asset)
- [ ] add action that can execute another brain

## Propositions

## Docs

I need to write an actual doc!

## Contribution

Create a dedicated file and move this section there!
