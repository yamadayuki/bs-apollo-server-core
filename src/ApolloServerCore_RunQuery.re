[@bs.deriving jsConverter]
type logAction = [
  | [@bs.as "request"] `Request
  | [@bs.as "parse"] `Parse
  | [@bs.as "validation"] `Validation
  | [@bs.as "execute"] `Execute
];

[@bs.deriving jsConverter]
type logStep = [
  | [@bs.as "start"] `Start
  | [@bs.as "end"] `End
  | [@bs.as "status"] `Status
];

type logMessage = {
  .
  "action": logAction,
  "step": logStep,
  "key": Js.null_undefined(string),
  "data": Js.null_undefined(Js.Types.obj_val),
};

type graphqlOptions('rootValue, 'context, 'response) = {
  .
  "schema": GraphQL.Type.schema,
  "query": string,
  "rootValue": Js.null_undefined('rootValue),
  "context": Js.null_undefined('context),
  "operationName": Js.null_undefined(string),
  "logFunction": Js.null_undefined(logMessage => unit),
  "validationRules": Js.null_undefined(GraphQL.Validation.validationConetxt),
  "fieldResolver":
    Js.null_undefined(
      GraphQL.Type.fieldResolver(Js.Types.obj_val, Js.Types.obj_val),
    ),
  "formatError": Js.null_undefined(Js.Exn.t => GraphQL.Error.error),
  "formatResponse":
    Js.null_undefined(
      GraphQL.Execution.executionResult(Js.Types.obj_val) => Js.t('response),
    ),
  "debug": Js.null_undefined(bool),
  "tracing": Js.null_undefined(bool),
};

let createGraphQLOptions =
    (
      ~rootValue: option('rootValue)=?,
      ~context: option('context)=?,
      ~operationName: option(string)=?,
      ~logFunction: option(logMessage => unit)=?,
      ~validationRules: option(GraphQL.Validation.validationConetxt)=?,
      ~fieldResolver:
         option(
           GraphQL.Type.fieldResolver(Js.Types.obj_val, Js.Types.obj_val),
         )=?,
      ~formatError: option(Js.Exn.t => GraphQL.Error.error)=?,
      ~formatResponse:
         option(
           GraphQL.Execution.executionResult(Js.Types.obj_val) =>
           Js.t('response),
         )=?,
      ~debug: option(bool)=?,
      ~tracing: option(bool)=?,
      schema: GraphQL.Type.schema,
      query: string,
    )
    : graphqlOptions('rootValue, 'context, 'response) => {
  "schema": schema,
  "query": query,
  "rootValue": Js.Null_undefined.fromOption(rootValue),
  "context": Js.Null_undefined.fromOption(context),
  "operationName": Js.Null_undefined.fromOption(operationName),
  "logFunction": Js.Null_undefined.fromOption(logFunction),
  "validationRules": Js.Null_undefined.fromOption(validationRules),
  "fieldResolver": Js.Null_undefined.fromOption(fieldResolver),
  "formatError": Js.Null_undefined.fromOption(formatError),
  "formatResponse": Js.Null_undefined.fromOption(formatResponse),
  "debug": Js.Null_undefined.fromOption(debug),
  "tracing": Js.Null_undefined.fromOption(tracing),
};

type graphqlResponse('response) = {
  .
  "data": Js.null_undefined('response),
  "errors": Js.null_undefined(array(GraphQL.Error.error)),
  "extensions": Js.Types.obj_val,
};
