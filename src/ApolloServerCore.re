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

type graphqlOptions('rootValue, 'context, 'response) =
  ApolloServerCore_RunQuery.graphqlOptions('rootValue, 'context, 'response);

module HttpQueryError = ApolloServerCore_RunHttpQuery.Error;

let createGraphQLOptions = createGraphQLOptions;
