open Jest;
open ExpectJs;

open BsGraphql;

let () =
  describe("runHttpQuery", () =>
    describe("handling a GET query", () => {
      let query = "{ testString }";
      let mockQuery = {
        "method": "GET",
        "query": {
          "query": query,
        },
        "options":
          ApolloServerCore.createGraphQLOptions(
            GraphQL.Utilities.buildSchema(
              "type Query { testString: String }",
            ),
            query,
            ~rootValue={"testString": () => "hello"},
          ),
      };

      testPromise("retrieves 'hello' as test string", () =>
        ApolloServerCore.runHttpQuery([||], mockQuery)
        |> Js.Promise.then_(execResult =>
             Js.Promise.resolve(
               expect(execResult)
               |> toEqual("{\"data\":{\"testString\":\"hello\"}}"),
             )
           )
      );
    })
  );
