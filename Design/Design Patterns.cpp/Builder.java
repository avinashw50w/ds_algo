/**
 * Builder pattern builds a complex object using simple objects and using a step by step approach. This type of design pattern comes under creational pattern as this pattern provides one of the best ways to create an object.

A Builder class builds the final object step by step. This builder is independent of other objects.

Lets say we have a class whose constructor contains many parameters, where
some parameters are required and some parameters are optional. Then we need to use
builder pattern here
 */

public class User {
    private String name;
    private int age;
    private String email;

    private User(UserBuilder builder) {
        this.name = builder.name;
        this.age = builder.age;
        this.email = builder.email;
    }

    public static class UserBuilder {
        private String name;
        private int age;
        private String email;

        public UserBuilder(String name) {
            this.name = name;
        }

        public UserBuilder setAge(int age) {
            this.age = age;
        }

        public UserBuilder setEmail(String email) {
            this.email = email;
        }

        public User build() {
            return new User(this);
        }

    }
}

public class Demo {
    public static void main(String[] args) {
        User user = new User.UserBuilder("avinash")
                    .setAge(27)
                    .setEmail("xyz@gmail.com")
                    .build();
    }
}