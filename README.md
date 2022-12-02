multiplication
add
sub
division
factorial
modulo
exponent
gcd
<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

[![PyPi][pypi-shield]][pypi-url]
[![PyPi][pypiversion-shield]][pypi-url]
[![PyPi][downloads-shield]][downloads-url]
[![Contributors][contributors-shield]][contributors-url]
[![License][license-shield]][license-url]
[![Build][build-shield]][build-url]
[![Interrogate][interrogate-shield]][interrogate-url]
<!-- [![CodeCov][codecov-shield]][codecov-url] -->

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[pypi-shield]: https://img.shields.io/pypi/pyversions/zenml?style=for-the-badge
[pypi-url]: https://pypi.org/project/zenml/
[pypiversion-shield]: https://img.shields.io/pypi/v/zenml?style=for-the-badge

[downloads-shield]: https://img.shields.io/pypi/dm/zenml?style=for-the-badge
[downloads-url]: https://pypi.org/project/zenml/
[codecov-shield]: https://img.shields.io/codecov/c/gh/zenml-io/zenml?style=for-the-badge
[codecov-url]: https://codecov.io/gh/zenml-io/zenml
[contributors-shield]: https://img.shields.io/github/contributors/zenml-io/zenml?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[license-shield]: https://img.shields.io/github/license/zenml-io/zenml?style=for-the-badge
[license-url]: https://github.com/zenml-io/zenml/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/company/zenml/
[twitter-shield]: https://img.shields.io/twitter/follow/zenml_io?style=for-the-badge
[twitter-url]: https://twitter.com/zenml_io
[slack-shield]: https://img.shields.io/badge/-Slack-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[slack-url]: https://zenml.io/slack-invite
[build-shield]: https://img.shields.io/github/workflow/status/zenml-io/zenml/Build,%20Lint,%20Unit%20&%20Integration%20Test/develop?logo=github&style=for-the-badge
[build-url]: https://github.com/zenml-io/zenml/actions/workflows/ci.yml
[interrogate-shield]: https://img.shields.io/badge/Interrogate-100%25-brightgreen?style=for-the-badge&logo=interrogate
[interrogate-url]: https://interrogate.readthedocs.io/en/latest/


<!-- PROJECT LOGO -->
<br />
<div align="center">
    <img src="assets/bigInt.jpg" alt="Logo" width="400">
  </a>

  <h3 align="center">Perform arithmatic operations of large digit numbers.</h3>

  <p align="center">
    A simple c++ header file containing fuctions for calulating addition, subtraction, multiplication, division, modulo, gcd, factorial, exponent of large numbers that doesn't fit into int or long long int data type.
    <br />
    🎉 Versio0n 0.0.1 is out. Check out the release notes
  </p>
</div>

# 💡 What is Big Integer Library?

Big Integer Library contains fuctions related to various arithmatic operations like
addition, subtraction, multiplication, division, modulo, gcd, factorial, exponent on large numbers that doesn't fit into int or long long int data type.
    <br /> 
Read more on all tools you can readily use in the [integrations](https://zenml.io/integrations) section. Can't find your tool? You can always [write your own integration](https://docs.zenml.io/advanced-guide/stacks/custom-flavors) to use it with ZenML.

# 🤸 Getting Started

## 💾 How to use .?
Include bigInt.h Header file into your c++ file using below code:

```cpp
#include "bigInt.h"
```
> **Note** - Big Integer Library supports C++11, C++14, and C++17.

## 🏇 Below are the examples of functions.

If you're you want to add two large numbers:

```cpp
string num1 = "16546313156645";
string num2 = "48798451351";
string result = add(num1, num2);
cout<<result<<endl;
```

If you're you want to subtract two large numbers:

```cpp
string num1 = "232688975318412";
string num2 = "116445186451";
string result = sub(num1, num2);
cout<<result<<endl;
```

If you're you want to multiply two large numbers:

```cpp
string num1 = "12168412158";
string num2 = "86746564554988";
string result = multiplication(num1, num2);
cout<<result<<endl;
```

If you're you want to divide two large numbers:

```cpp
string num1 = "15464841654645598";
string num2 = "787665431513216";
string result = division(num1, num2);
cout<<result<<endl;
```

If you're you want to find factorial of large number:

```cpp
string num = "9875114";
string result = factorial(num);
cout<<result<<endl;
```

If you're you want to find gcd of two large numbers:

```cpp
string num1 = "15464841654645598";
string num2 = "787665431513216";
string result = gcd(num1, num2);
cout<<result<<endl;
```

If you're you want to find modulo of two large numbers:

```cpp
string num1 = "15464841654645598";
string num2 = "787665431513216";
string result = modulo(num1, num2);
cout<<result<<endl;
```

If you're you want to find exponent of two large numbers:

```cpp
string num1 = "15464841654645598";
string num2 = "787665431513216";
string result = exponent(num1, num2);
cout<<result<<endl;
```

If you're you want to find exponent of two large numbers:

```cpp
string num1 = "15464841654645598";
string num2 = "787665431513216";
string result = exponent(num1, num2);
cout<<result<<endl;
```



This spins up a Jupyter notebook that walks you through various functionalities of ZenML at a high level.

By the end, you'll get a glimpse of how to use ZenML to register a stack:

```shell
# Register a MLflow experiment tracker
zenml experiment-tracker register mlflow_tracker --flavor=mlflow

# Register an Airflow orchestrator
zenml airflow register airflow_orchestrator --flavor=airflow

# Create a stack from the components
zenml stack register my_stack -o airflow_orchestrator -a default -e mlflow_tracker
```

And run a simple pipeline on Airflow (or an orchestrator of your choice) creating steps like this:

```python
import mlflow
from sklearn.base import ClassifierMixin
from sklearn.svm import SVC
from zenml.client import Client

experiment_tracker = Client().active_stack.experiment_tracker

@step(experiment_tracker=experiment_tracker.name)
def svc_trainer_mlflow(
    X_train: pd.DataFrame,
    y_train: pd.Series,
) -> ClassifierMixin:
    """Train a sklearn SVC classifier and log to MLflow."""
    mlflow.sklearn.autolog()  # log all model hparams and metrics to MLflow
    model = SVC(gamma=0.01)
    model.fit(X_train.to_numpy(), y_train.to_numpy())
    train_acc = model.score(X_train.to_numpy(), y_train.to_numpy())
    print(f"Train accuracy: {train_acc}")
    return model
```

You can also run your first pipeline right in [Google Colab](https://colab.research.google.com/github/zenml-io/zenml/blob/main/examples/quickstart/notebooks/quickstart.ipynb)

## 👭 Collaborate with ZenML

ZenML is built to support teams working together. 
The underlying infrastructure on which your ML workflows run can be shared, as can the data, assets, and artifacts in your workflow. 

To visually see this in action, ZenML ships with a fully-featured dashboard, that can be launched locally with the simple command:

```
zenml up
```

![ZenML Dashboard](docs/book/assets/getting_started/zenml-up.gif)

The dashboard can also be deployed with a server on any cloud service (see Deploy ZenML section).


## 🍰 ZenBytes

New to MLOps? Get up to speed by visiting the [ZenBytes](https://github.com/zenml-io/zenbytes) repo.

>ZenBytes is a series of short practical MLOps lessons taught using ZenML. 
>It covers many of the [core concepts](https://docs.zenml.io/getting-started/core-concepts) widely used in ZenML and MLOps in general.

## 📜 ZenFiles

Already comfortable with ZenML and wish to elevate your pipeline into production mode? Check out [ZenFiles](https://github.com/zenml-io/zenfiles).

>ZenFiles is a collection of production-grade ML use-cases powered by ZenML. They are fully fleshed out, end-to-end projects that showcase ZenML's capabilities. They can also serve as a template from which to start similar projects.


# ☁️ Infrastructure Requirements

## 🔋 Deploy ZenML

While ZenML works perfectly fine locally, it should be deployed on the cloud to enable collaborative features as the central MLOps interface for teams.

The easiest and fastest way to get running on the cloud is by using the `deploy` CLI command. It currently only supports deploying to Kubernetes on managed cloud services. Read more about the command [here](https://docs.zenml.io/getting-started/deploying-zenml/deploying-zenml).

```shell
zenml deploy
```

Naturally, [the docs](https://docs.zenml.io/getting-started/deploying-zenml/deploying-zenml) contain detailed guides on how to manually set up ZenML on the cloud in case more control is required.

The following architectural diagram illustrates a common ZenML deployment:

![ZenML Architecture Diagram.](docs/book/assets/getting_started/Scenario3.2.png)

## 👨‍🍳 Open Source MLOps Stack Recipes

Apart from the infrastructure required to run ZenML itself, ZenML also boasts a ton of [integrations](https://zenml.io/integrations) into popular MLOps tools. The [ZenML Stack](https://docs.zenml.io/starter-guide/stacks/stacks) concept ensures that these tools work nicely together, therefore bringing structure and standardization into the MLOps workflow.

However, ZenML assumes that the stack infrastructure for these tools is already provisioned. If you do not have deployed infrastructure, and want to quickly spin up combinations of tools on the cloud, the [MLOps stack sister repository](https://github.com/zenml-io/mlops-stacks) contains a series of Terraform-based recipes to provision such stacks. These recipes can be used directly with ZenML:

```bash
pip install "zenml[stacks]"

zenml stack recipe deploy <NAME_OF_STACK_RECIPE> --import
```

The above command not only provisions the given tools, but also automatically creates a ZenML stack with the configuration of the deployed recipe!


# 🗺 Roadmap

ZenML is being built in public. The [roadmap](https://zenml.io/roadmap) is a
regularly updated source of truth for the ZenML community to understand where
the product is going in the short, medium, and long term.

ZenML is managed by a [core team](https://zenml.io/company#CompanyTeam) of developers that are
responsible for making key decisions and incorporating feedback from the
community. The team oversees feedback via various channels, and you can directly
influence the roadmap as follows:

- Vote on your most wanted feature on our [Discussion
  board](https://zenml.io/discussion).
- Start a thread in our [Slack channel](https://zenml.io/slack-invite).
- [Create an issue](https://github.com/zenml-io/zenml/issues/new/choose) on our Github repo.

# 🙌 Contributing and Community

We would love to develop ZenML together with our community! Best way to get
started is to select any issue from the [`good-first-issue`
label](https://github.com/zenml-io/zenml/labels/good%20first%20issue). If you
would like to contribute, please review our [Contributing
Guide](CONTRIBUTING.md) for all relevant details.

<br>

![Repobeats analytics
image](https://repobeats.axiom.co/api/embed/635c57b743efe649cadceba6a2e6a956663f96dd.svg
"Repobeats analytics image")


# 👩‍👩‍👧‍👦 Meet the Team

![Meet the Team](./docs/book/assets/meet_the_team.png)

Have a question that's too hard to express on our Slack? Is it just too much effort to say everything on a 
long GitHub issue? Or are you just curious about what ZenML has been up to in the past week? Well, register now for the ZenML Office (Half) Hour to get your answers and more!
It's free and open to everyone.

Every week, part of the ZenML [core team](https://zenml.io/company#CompanyTeam) will pop in for 30 minutes to interact directly with the community. Sometimes we'll be presenting a feature. Other times we just take questions and have fun. Join us if you are curious about ZenML, or just want to talk shop about MLOps.



We will host the gathering every Wednesday 8:30AM PT (5:30PM CET). 
Register now through [this link](https://www.eventbrite.com/e/zenml-meet-the-community-tickets-354426688767), 
or subscribe to the [public events calendar](https://calendar.google.com/calendar/u/0/r?cid=Y19iaDJ0Zm44ZzdodXBlbnBzaWplY3UwMmNjZ0Bncm91cC5jYWxlbmRhci5nb29nbGUuY29t) to get notified 
before every community gathering.

# 🆘 Getting Help

The first point of call should be [our Slack group](https://zenml.io/slack-invite/).
Ask your questions about bugs or specific use cases, and someone from the [core team](https://zenml.io/company#CompanyTeam) will respond.
Or, if you prefer, [open an issue](https://github.com/zenml-io/zenml/issues/new/choose) on our GitHub repo.


# 📜 License

ZenML is distributed under the terms of the Apache License Version 2.0. 
A complete version of the license is available in the [LICENSE](LICENSE) file in
this repository. Any contribution made to this project will be licensed under
the Apache License Version 2.0.

# 📖 Learn More

| ZenML Resources | Description |
| ------------- | - |
| 🧘‍♀️ **[ZenML 101]** | New to ZenML? Here's everything you need to know! |
| ⚛️ **[Core Concepts]** | Some key terms and concepts we use. |
| 🚀 **[Our latest release]** | New features, bug fixes. |
| 🗳 **[Vote for Features]** | Pick what we work on next! |
| 📓 **[Docs]** | Full documentation for creating your own ZenML pipelines. |
| 📒 **[API Reference]** | Detailed reference on ZenML's API. |
| 🍰 **[ZenBytes]** | A guided and in-depth tutorial on MLOps and ZenML. |
| 🗂️️ **[ZenFiles]** | End-to-end projects using ZenML. |
| 👨‍🍳 **[MLOps Stacks]** | Terraform based infrastructure recipes for pre-made ZenML stacks. |
| ⚽️ **[Examples]** | Learn best through examples where ZenML is used? We've got you covered. |
| 📬 **[Blog]** | Use cases of ZenML and technical deep dives on how we built it. |
| 🔈 **[Podcast]** | Conversations with leaders in ML, released every 2 weeks. |
| 📣 **[Newsletter]** | We build ZenML in public. Subscribe to learn how we work. |
| 💬 **[Join Slack]** | Need help with your specific use case? Say hi on Slack! |
| 🗺 **[Roadmap]** | See where ZenML is working to build new features. |
| 🙋‍♀️ **[Contribute]** | How to contribute to the ZenML project and code base. |

[ZenML 101]: https://docs.zenml.io/
[Core Concepts]: https://docs.zenml.io/getting-started/core-concepts
[Deployment Guide]: TBD
[Our latest release]: https://github.com/zenml-io/zenml/releases
[Vote for Features]: https://zenml.io/discussion
[Docs]: https://docs.zenml.io/
[API Reference]: https://apidocs.zenml.io/
[ZenBytes]: https://github.com/zenml-io/zenbytes
[ZenFiles]: https://github.com/zenml-io/zenfiles
[MLOps Stacks]: https://github.com/zenml-io/mlops-stacks
[Examples]: https://github.com/zenml-io/zenml/tree/main/examples
[Blog]: https://blog.zenml.io/
[Podcast]: https://podcast.zenml.io/
[Newsletter]: https://zenml.io/newsletter/
[Join Slack]: https://zenml.io/slack-invite/
[Roadmap]: https://zenml.io/roadmap
[Contribute]: https://github.com/zenml-io/zenml/blob/main/CONTRIBUTING.md
