open ApolloServerCore_RunQuery;
open ApolloServerCore_RunHttpQuery;

[@bs.module "apollo-server-core"]
external runQuery :
  graphqlOptions('rootValue, 'context, 'response) =>
  Js.Promise.t(graphqlResponse('response)) =
  "";

[@bs.module "apollo-server-core"]
external runHttpQuery :
  (array('a), httpQueryRequest('rootValue, 'context, 'response)) =>
  Js.Promise.t(string) =
  "";

let createGraphQLOptions = createGraphQLOptions;
