open ApolloServerCore_RunQuery;

module Error = {
  type error = {
    .
    "message": string,
    "statusCode": int,
    "isGraphQLError": bool,
    "headers": Js.nullable(Js.Types.obj_val),
  };
};

type httpQueryRequest('rootValue, 'context, 'response) = {
  .
  "method": string,
  "query": {. "query": string},
  "options": graphqlOptions('rootValue, 'context, 'response),
};
